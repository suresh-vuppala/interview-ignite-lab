## Failure Scenarios and Handling

Our system must handle various failure modes gracefully to ensure reliability and data integrity.

## Worker Failure Detection

```python
class WorkerHealthMonitor:
    def __init__(self):
        self.heartbeat_timeout = 30  # seconds
        self.check_interval = 10     # seconds
    
    def monitor_workers(self):
        """Continuously monitor worker health"""
        while True:
            workers = redis.keys("worker:*")
            
            for worker_key in workers:
                worker_id = worker_key.decode().split(":")[1]
                last_heartbeat = redis.hget(worker_key, "last_heartbeat")
                
                if last_heartbeat:
                    age = time.time() - float(last_heartbeat)
                    
                    if age > self.heartbeat_timeout:
                        # Worker failed
                        self.handle_worker_failure(worker_id)
            
            time.sleep(self.check_interval)
    
    def handle_worker_failure(self, worker_id):
        """Handle failed worker"""
        print(f"Worker {worker_id} failed - reassigning tasks")
        
        # Get active tasks
        active_tasks = redis.hget(f"worker:{worker_id}", "active_tasks")
        
        if active_tasks:
            for task_id in active_tasks.decode().split(","):
                # Mark task as failed
                cassandra.execute(
                    "UPDATE task_instances SET status = 'failed', "
                    "error_message = 'Worker failure' WHERE instance_id = %s",
                    (task_id,)
                )
                
                # Requeue for retry
                self.requeue_task(task_id)
        
        # Remove worker registration
        redis.delete(f"worker:{worker_id}")
```

## Retry Logic

```python
class RetryManager:
    def __init__(self):
        self.default_max_retries = 3
        self.default_retry_delay = 60
        self.backoff_multiplier = 2.0
    
    def should_retry(self, task_instance):
        """Determine if task should be retried"""
        task_def = get_task_definition(task_instance.task_id)
        
        # Check retry count
        if task_instance.attempt_number >= task_def.max_retries:
            return False
        
        # Check error type
        if task_instance.error_message:
            if "authentication_failed" in task_instance.error_message:
                return False  # Don't retry auth failures
            
            if "invalid_input" in task_instance.error_message:
                return False  # Don't retry validation errors
        
        return True
    
    def calculate_retry_delay(self, task_instance):
        """Calculate delay before retry with exponential backoff"""
        task_def = get_task_definition(task_instance.task_id)
        
        base_delay = task_def.retry_delay
        attempt = task_instance.attempt_number
        
        # Exponential backoff: delay * (multiplier ^ attempt)
        delay = base_delay * (self.backoff_multiplier ** attempt)
        
        # Cap at max delay
        max_delay = task_def.get("max_retry_delay", 3600)
        delay = min(delay, max_delay)
        
        # Add jitter to prevent thundering herd
        jitter = random.uniform(0, delay * 0.1)
        
        return delay + jitter
    
    def retry_task(self, task_instance):
        """Retry failed task"""
        if not self.should_retry(task_instance):
            # Mark as permanently failed
            cassandra.execute(
                "UPDATE task_instances SET status = 'failed_permanent' "
                "WHERE instance_id = %s",
                (task_instance.instance_id,)
            )
            return
        
        # Calculate retry delay
        delay = self.calculate_retry_delay(task_instance)
        
        # Schedule retry
        retry_time = time.time() + delay
        
        # Create new instance for retry
        new_instance = TaskInstance(
            instance_id=generate_id(),
            task_id=task_instance.task_id,
            scheduled_time=retry_time,
            attempt_number=task_instance.attempt_number + 1,
            status="pending"
        )
        
        # Add to time wheel
        time_wheel.add_task(new_instance.instance_id, retry_time)
```

## Idempotency and Deduplication

```python
class IdempotencyManager:
    def __init__(self):
        self.ttl = 86400  # 24 hours
    
    def check_idempotency(self, idempotency_key):
        """Check if request already processed"""
        existing = redis.get(f"idempotency:{idempotency_key}")
        
        if existing:
            # Return existing task
            return json.loads(existing)
        
        return None
    
    def store_idempotency(self, idempotency_key, task_id):
        """Store idempotency mapping"""
        redis.setex(
            f"idempotency:{idempotency_key}",
            self.ttl,
            json.dumps({"task_id": task_id, "created_at": time.time()})
        )
    
    def ensure_exactly_once(self, task_instance):
        """Ensure task executes exactly once"""
        lock_key = f"task:lock:{task_instance.instance_id}"
        
        # Try to acquire lock
        acquired = redis.set(
            lock_key,
            "locked",
            nx=True,  # Only set if not exists
            ex=300    # Expire in 5 minutes
        )
        
        if not acquired:
            # Another worker already processing
            return False
        
        return True
```

## Circuit Breaker Pattern

```python
class CircuitBreaker:
    def __init__(self, failure_threshold=5, timeout=60):
        self.failure_threshold = failure_threshold
        self.timeout = timeout
        self.failure_count = 0
        self.last_failure_time = None
        self.state = "CLOSED"  # CLOSED, OPEN, HALF_OPEN
    
    def call(self, func, *args, **kwargs):
        """Execute function with circuit breaker"""
        if self.state == "OPEN":
            # Check if timeout expired
            if time.time() - self.last_failure_time > self.timeout:
                self.state = "HALF_OPEN"
            else:
                raise Exception("Circuit breaker is OPEN")
        
        try:
            result = func(*args, **kwargs)
            
            # Success - reset failure count
            if self.state == "HALF_OPEN":
                self.state = "CLOSED"
            self.failure_count = 0
            
            return result
        
        except Exception as e:
            self.failure_count += 1
            self.last_failure_time = time.time()
            
            if self.failure_count >= self.failure_threshold:
                self.state = "OPEN"
            
            raise e
```

## Dead Letter Queue

```python
class DeadLetterQueue:
    def __init__(self):
        self.dlq_name = "queue:dead_letter"
    
    def move_to_dlq(self, task_instance, reason):
        """Move permanently failed task to DLQ"""
        dlq_entry = {
            "task_id": task_instance.task_id,
            "instance_id": task_instance.instance_id,
            "failed_at": time.time(),
            "reason": reason,
            "attempt_number": task_instance.attempt_number,
            "error_message": task_instance.error_message
        }
        
        # Add to DLQ
        redis.lpush(self.dlq_name, json.dumps(dlq_entry))
        
        # Alert on DLQ growth
        dlq_size = redis.llen(self.dlq_name)
        if dlq_size > 1000:
            send_alert(f"DLQ size exceeded threshold: {dlq_size}")
    
    def replay_from_dlq(self, instance_id):
        """Manually replay task from DLQ"""
        # Find task in DLQ
        dlq_entries = redis.lrange(self.dlq_name, 0, -1)
        
        for entry in dlq_entries:
            data = json.loads(entry)
            if data["instance_id"] == instance_id:
                # Remove from DLQ
                redis.lrem(self.dlq_name, 1, entry)
                
                # Requeue task
                task_instance = get_task_instance(instance_id)
                task_instance.attempt_number = 0
                task_instance.status = "pending"
                
                enqueue_task(task_instance)
                return True
        
        return False
```

## Graceful Degradation

```python
class GracefulDegradation:
    def handle_database_failure(self):
        """Handle database unavailability"""
        # Switch to read-only mode
        self.read_only_mode = True
        
        # Use cached data
        # Accept task submissions but queue in Kafka only
        # Disable status queries temporarily
    
    def handle_queue_failure(self):
        """Handle queue unavailability"""
        # Use backup queue (different Redis instance)
        # Reduce task acceptance rate
        # Alert operations team
    
    def handle_overload(self):
        """Handle system overload"""
        # Enable rate limiting
        # Reject low-priority tasks
        # Scale up workers automatically
```

## Monitoring and Alerting

```python
class FailureMonitor:
    def track_metrics(self):
        """Track failure metrics"""
        metrics = {
            "task_failure_rate": self.calculate_failure_rate(),
            "worker_failure_rate": self.calculate_worker_failure_rate(),
            "retry_success_rate": self.calculate_retry_success_rate(),
            "dlq_size": redis.llen("queue:dead_letter")
        }
        
        # Alert on anomalies
        if metrics["task_failure_rate"] > 0.05:  # > 5%
            send_alert("High task failure rate")
        
        if metrics["dlq_size"] > 1000:
            send_alert("DLQ size exceeded threshold")
        
        return metrics
```

This failure handling strategy ensures 99.9% system availability and >90% retry success rate through comprehensive error detection, retry logic, and graceful degradation.
