## Task Queue Architecture

Our system uses a multi-tier queue architecture to handle different priorities and ensure fair task distribution.

## Queue Structure

```
┌─────────────────────────────────────────┐
│         Priority Queues (Redis)         │
├─────────────────────────────────────────┤
│  Critical Queue (P10)   │ 100 tasks     │
│  High Queue (P7-9)      │ 5,000 tasks   │
│  Normal Queue (P4-6)    │ 50,000 tasks  │
│  Low Queue (P1-3)       │ 20,000 tasks  │
│  Best Effort Queue (P0) │ 10,000 tasks  │
└─────────────────────────────────────────┘
```

## Priority-Based Dequeuing

```python
class PriorityTaskQueue:
    def __init__(self):
        self.queues = {
            10: "queue:critical",
            9: "queue:high",
            6: "queue:normal",
            3: "queue:low",
            0: "queue:best_effort"
        }
        self.weights = {
            10: 0.40,  # 40% of capacity
            9: 0.30,   # 30% of capacity
            6: 0.20,   # 20% of capacity
            3: 0.08,   # 8% of capacity
            0: 0.02    # 2% of capacity
        }
    
    def dequeue_task(self, worker_capacity):
        """Weighted fair queuing"""
        for priority in sorted(self.queues.keys(), reverse=True):
            queue_name = self.queues[priority]
            weight = self.weights[priority]
            
            # Calculate tasks to fetch from this queue
            tasks_to_fetch = int(worker_capacity * weight)
            
            if tasks_to_fetch > 0:
                tasks = redis.lrange(queue_name, 0, tasks_to_fetch - 1)
                if tasks:
                    redis.ltrim(queue_name, tasks_to_fetch, -1)
                    return tasks
        
        return []
```

## Queue Operations

### Enqueue with Priority

```python
def enqueue_task(task_id, priority):
    """Add task to appropriate priority queue"""
    queue_name = get_queue_for_priority(priority)
    
    # Add to queue with score (for sorting)
    redis.zadd(queue_name, {
        task_id: time.time()  # Score = enqueue time
    })
    
    # Update queue metrics
    redis.incr(f"metrics:queue:{queue_name}:enqueued")
```

### Dequeue for Worker

```python
def dequeue_for_worker(worker_id, max_tasks=10):
    """Worker polls for tasks"""
    tasks = []
    
    # Try each priority queue in order
    for priority in [10, 9, 6, 3, 0]:
        queue_name = get_queue_for_priority(priority)
        
        # Atomic pop with timeout (blocking)
        task_id = redis.bzpopmin(queue_name, timeout=30)
        
        if task_id:
            # Claim task for this worker
            redis.setex(f"task:{task_id}:worker", 300, worker_id)
            tasks.append(task_id)
            
            if len(tasks) >= max_tasks:
                break
    
    return tasks
```

## Queue Monitoring

```python
class QueueMonitor:
    def get_queue_depth(self):
        """Get current queue sizes"""
        depths = {}
        for priority, queue_name in self.queues.items():
            depths[priority] = redis.zcard(queue_name)
        return depths
    
    def get_queue_lag(self):
        """Calculate time since oldest task enqueued"""
        lags = {}
        for priority, queue_name in self.queues.items():
            oldest = redis.zrange(queue_name, 0, 0, withscores=True)
            if oldest:
                enqueue_time = oldest[0][1]
                lags[priority] = time.time() - enqueue_time
        return lags
    
    def should_scale_workers(self):
        """Determine if we need more workers"""
        depths = self.get_queue_depth()
        total_depth = sum(depths.values())
        
        # Scale up if queue depth > 10,000
        if total_depth > 10000:
            return True
        
        # Scale up if lag > 60 seconds for high priority
        lags = self.get_queue_lag()
        if lags.get(10, 0) > 60 or lags.get(9, 0) > 120:
            return True
        
        return False
```

## Fair Scheduling

### Weighted Fair Queuing

```python
def weighted_fair_dequeue(worker_count=5000):
    """Distribute tasks fairly across priorities"""
    
    # Calculate capacity per priority
    capacities = {
        10: int(worker_count * 0.40),  # 2000 workers
        9: int(worker_count * 0.30),   # 1500 workers
        6: int(worker_count * 0.20),   # 1000 workers
        3: int(worker_count * 0.08),   # 400 workers
        0: int(worker_count * 0.02)    # 100 workers
    }
    
    # Dequeue tasks for each priority
    for priority, capacity in capacities.items():
        queue_name = get_queue_for_priority(priority)
        tasks = redis.zrange(queue_name, 0, capacity - 1)
        
        # Assign to workers
        for task_id in tasks:
            assign_to_worker(task_id, priority)
```

### Starvation Prevention

```python
def prevent_starvation():
    """Ensure low-priority tasks eventually execute"""
    
    # Check age of oldest low-priority task
    low_queue = "queue:low"
    oldest = redis.zrange(low_queue, 0, 0, withscores=True)
    
    if oldest:
        enqueue_time = oldest[0][1]
        age = time.time() - enqueue_time
        
        # If task waiting > 1 hour, boost priority
        if age > 3600:
            task_id = oldest[0][0]
            
            # Move to normal priority queue
            redis.zrem(low_queue, task_id)
            redis.zadd("queue:normal", {task_id: time.time()})
            
            print(f"Boosted priority for task {task_id} due to age")
```

## Queue Persistence

```python
class PersistentQueue:
    def __init__(self):
        self.redis = redis.StrictRedis()
        self.kafka = KafkaProducer()
    
    def enqueue_with_persistence(self, task_id, priority):
        """Enqueue with Kafka backup"""
        
        # Add to Redis queue (fast)
        queue_name = get_queue_for_priority(priority)
        self.redis.zadd(queue_name, {task_id: time.time()})
        
        # Backup to Kafka (durable)
        self.kafka.send('task-queue-backup', {
            'task_id': task_id,
            'priority': priority,
            'enqueued_at': time.time()
        })
    
    def recover_from_kafka(self):
        """Recover queue from Kafka on Redis failure"""
        consumer = KafkaConsumer('task-queue-backup')
        
        for message in consumer:
            task_id = message['task_id']
            priority = message['priority']
            
            # Check if task already completed
            if not is_task_completed(task_id):
                # Re-enqueue
                queue_name = get_queue_for_priority(priority)
                self.redis.zadd(queue_name, {task_id: time.time()})
```

## Queue Sharding

```python
class ShardedQueue:
    def __init__(self, num_shards=10):
        self.num_shards = num_shards
    
    def get_shard(self, task_id):
        """Determine shard for task"""
        return hash(task_id) % self.num_shards
    
    def enqueue(self, task_id, priority):
        """Enqueue to sharded queue"""
        shard = self.get_shard(task_id)
        queue_name = f"queue:priority:{priority}:shard:{shard}"
        
        redis.zadd(queue_name, {task_id: time.time()})
    
    def dequeue(self, worker_id):
        """Dequeue from assigned shard"""
        shard = self.get_shard(worker_id)
        
        for priority in [10, 9, 6, 3, 0]:
            queue_name = f"queue:priority:{priority}:shard:{shard}"
            task_id = redis.bzpopmin(queue_name, timeout=30)
            
            if task_id:
                return task_id
        
        return None
```

This queue architecture ensures fair task distribution, prevents starvation, and scales to handle 100,000 concurrent task executions.
