## Worker Architecture

Workers are stateless execution engines that poll for tasks, execute them, and report results.

## Worker Lifecycle

```python
class TaskWorker:
    def __init__(self, worker_id, task_types):
        self.worker_id = worker_id
        self.task_types = task_types
        self.max_concurrent = 20
        self.active_tasks = {}
        self.running = True
    
    def start(self):
        """Main worker loop"""
        # Register worker
        self.register()
        
        # Start heartbeat thread
        threading.Thread(target=self.send_heartbeats, daemon=True).start()
        
        # Main execution loop
        while self.running:
            try:
                # Poll for tasks
                tasks = self.poll_tasks()
                
                # Execute tasks concurrently
                for task in tasks:
                    if len(self.active_tasks) < self.max_concurrent:
                        threading.Thread(
                            target=self.execute_task,
                            args=(task,),
                            daemon=True
                        ).start()
                
                time.sleep(1)
            
            except Exception as e:
                print(f"Worker error: {e}")
                time.sleep(5)
    
    def register(self):
        """Register worker with scheduler"""
        redis.hset(f"worker:{self.worker_id}", mapping={
            "status": "active",
            "task_types": ",".join(self.task_types),
            "max_concurrent": self.max_concurrent,
            "registered_at": time.time()
        })
    
    def poll_tasks(self):
        """Poll for available tasks"""
        response = grpc_client.PollTasks(
            worker_id=self.worker_id,
            task_types=self.task_types,
            max_tasks=self.max_concurrent - len(self.active_tasks),
            timeout_seconds=30
        )
        return response.tasks
    
    def execute_task(self, task):
        """Execute single task"""
        instance_id = task.instance_id
        self.active_tasks[instance_id] = task
        
        try:
            # Update status to running
            self.update_status(instance_id, "RUNNING")
            
            # Execute task logic
            result = self.run_task_logic(task)
            
            # Update status to completed
            self.update_status(instance_id, "COMPLETED", result=result)
        
        except Exception as e:
            # Update status to failed
            self.update_status(instance_id, "FAILED", error=str(e))
        
        finally:
            del self.active_tasks[instance_id]
    
    def run_task_logic(self, task):
        """Execute actual task"""
        task_type = task.task_type
        payload = json.loads(task.payload)
        
        # Route to appropriate handler
        handler = self.get_handler(task_type)
        return handler(payload)
    
    def send_heartbeats(self):
        """Send periodic heartbeats"""
        while self.running:
            try:
                grpc_client.Heartbeat(
                    worker_id=self.worker_id,
                    active_task_ids=list(self.active_tasks.keys()),
                    metrics={
                        "cpu_usage": psutil.cpu_percent(),
                        "memory_usage": psutil.virtual_memory().percent,
                        "active_tasks": len(self.active_tasks)
                    }
                )
                time.sleep(10)
            except Exception as e:
                print(f"Heartbeat failed: {e}")
    
    def shutdown(self):
        """Graceful shutdown"""
        self.running = False
        
        # Wait for active tasks to complete (max 5 minutes)
        timeout = time.time() + 300
        while self.active_tasks and time.time() < timeout:
            time.sleep(1)
        
        # Unregister worker
        redis.delete(f"worker:{self.worker_id}")
```

## Task Execution Patterns

### Timeout Handling

```python
def execute_with_timeout(task, timeout):
    """Execute task with timeout"""
    import signal
    
    def timeout_handler(signum, frame):
        raise TimeoutError(f"Task exceeded timeout of {timeout}s")
    
    # Set timeout
    signal.signal(signal.SIGALRM, timeout_handler)
    signal.alarm(timeout)
    
    try:
        result = execute_task(task)
        signal.alarm(0)  # Cancel timeout
        return result
    except TimeoutError as e:
        # Mark task as failed due to timeout
        update_status(task.instance_id, "FAILED", error=str(e))
        raise
```

### Progress Reporting

```python
def execute_with_progress(task):
    """Execute task with progress updates"""
    total_steps = 100
    
    for step in range(total_steps):
        # Do work
        process_step(step)
        
        # Report progress every 10%
        if step % 10 == 0:
            progress = (step / total_steps) * 100
            grpc_client.UpdateTaskStatus(
                instance_id=task.instance_id,
                status="RUNNING",
                progress_percentage=progress
            )
```

## Worker Pool Management

### Auto-Scaling

```python
class WorkerPoolManager:
    def __init__(self):
        self.min_workers = 1000
        self.max_workers = 10000
        self.target_queue_depth = 5000
    
    def scale_workers(self):
        """Auto-scale based on queue depth"""
        queue_depth = get_total_queue_depth()
        current_workers = get_active_worker_count()
        
        # Calculate desired workers
        desired_workers = queue_depth / 20  # 20 tasks per worker
        desired_workers = max(self.min_workers, min(desired_workers, self.max_workers))
        
        if desired_workers > current_workers * 1.2:
            # Scale up by 20%
            scale_up(int(current_workers * 0.2))
        elif desired_workers < current_workers * 0.8:
            # Scale down by 20%
            scale_down(int(current_workers * 0.2))
```

### Health Monitoring

```python
def monitor_worker_health():
    """Monitor and recover unhealthy workers"""
    workers = redis.keys("worker:*")
    
    for worker_key in workers:
        worker_id = worker_key.split(":")[1]
        last_heartbeat = redis.hget(worker_key, "last_heartbeat")
        
        if time.time() - float(last_heartbeat) > 30:
            # Worker is unhealthy
            print(f"Worker {worker_id} is unhealthy")
            
            # Get active tasks
            active_tasks = redis.hget(worker_key, "active_tasks")
            
            # Reassign tasks
            for task_id in active_tasks.split(","):
                reassign_task(task_id)
            
            # Remove worker
            redis.delete(worker_key)
```

This worker architecture supports 5,000 concurrent workers executing 100,000 tasks with fault tolerance and auto-scaling.
