## System Architecture Evolution

### Level 1: Black Box View

```
┌─────────┐         ┌──────────────────┐         ┌─────────┐
│ Clients │────────>│  Job Scheduler   │────────>│ Workers │
└─────────┘         │     System       │         └─────────┘
                    └──────────────────┘
```

**Core responsibilities:**
- Accept task submissions
- Schedule tasks at specified times
- Distribute tasks to workers
- Track execution status

### Level 2: Major Components

```
┌─────────┐
│ Clients │
└────┬────┘
     │
     v
┌─────────────────┐
│   API Gateway   │ ← Load balancer, rate limiting
└────┬────────────┘
     │
     v
┌─────────────────┐
│  Task Ingestion │ ← Validate, persist, enqueue
└────┬────────────┘
     │
     v
┌─────────────────┐
│   Task Queue    │ ← Kafka/RabbitMQ
└────┬────────────┘
     │
     v
┌─────────────────┐
│   Schedulers    │ ← Time-wheel, task distribution
└────┬────────────┘
     │
     v
┌─────────────────┐
│  Worker Pool    │ ← Execute tasks
└─────────────────┘
```

### Level 3: Data Flow

```
Task Submission Flow:
Client → API Gateway → Task Service → Kafka → Scheduler → Worker

1. Client submits task via REST API
2. API Gateway validates and rate limits
3. Task Service persists to PostgreSQL
4. Task published to Kafka topic
5. Scheduler consumes from Kafka
6. Scheduler adds to time-wheel
7. At scheduled time, task pushed to execution queue
8. Worker polls and executes task
9. Worker updates status
```

### Level 4: Complete Architecture

```
                    ┌──────────────┐
                    │   Clients    │
                    └──────┬───────┘
                           │
                    ┌──────v───────┐
                    │ Load Balancer│
                    └──────┬───────┘
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
   ┌────v────┐       ┌────v────┐       ┌────v────┐
   │ API     │       │ API     │       │ API     │
   │ Server 1│       │ Server 2│       │ Server N│
   └────┬────┘       └────┬────┘       └────┬────┘
        │                  │                  │
        └──────────────────┼──────────────────┘
                           │
                    ┌──────v───────┐
                    │  PostgreSQL  │ ← Task definitions
                    │   (Primary)  │
                    └──────┬───────┘
                           │
                    ┌──────v───────┐
                    │    Kafka     │ ← Task submission queue
                    └──────┬───────┘
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
   ┌────v────┐       ┌────v────┐       ┌────v────┐
   │Scheduler│       │Scheduler│       │Scheduler│
   │   1     │       │   2     │       │   N     │
   └────┬────┘       └────┬────┘       └────┬────┘
        │                  │                  │
        │            ┌─────v─────┐            │
        │            │   Redis   │            │
        └───────────>│ Task Queue│<───────────┘
                     └─────┬─────┘
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
   ┌────v────┐       ┌────v────┐       ┌────v────┐
   │ Worker  │       │ Worker  │       │ Worker  │
   │   1     │       │   2     │       │  5000   │
   └────┬────┘       └────┬────┘       └────┬────┘
        │                  │                  │
        └──────────────────┼──────────────────┘
                           │
                    ┌──────v───────┐
                    │  Cassandra   │ ← Execution history
                    └──────────────┘
```

### Level 5: Component Details

**API Servers (50 nodes):**
- Handle REST API requests
- Validate task definitions
- Enforce rate limits (token bucket)
- Write to PostgreSQL and Kafka
- Stateless, horizontally scalable

**Schedulers (100 nodes):**
- Consume from Kafka (task submissions)
- Maintain time-wheel data structure
- Move tasks from time-wheel to execution queue
- Handle task dependencies (DAG resolution)
- Leader election for coordination

**Workers (5,000 nodes):**
- Poll Redis for tasks (long polling)
- Execute task logic
- Send heartbeats every 10 seconds
- Update task status to Cassandra
- Support graceful shutdown

**Storage:**
- **PostgreSQL**: Task definitions, metadata
- **Kafka**: Task submission queue (retention: 7 days)
- **Redis**: Active task queue, worker registry
- **Cassandra**: Task execution history (retention: 30 days)

### Level 6: Failure Scenarios

**API Server Failure:**
- Load balancer detects failure (health check)
- Routes traffic to healthy servers
- No data loss (stateless)

**Scheduler Failure:**
- Other schedulers detect via heartbeat
- Tasks reassigned using consistent hashing
- In-flight tasks recovered from Kafka

**Worker Failure:**
- Scheduler detects missed heartbeats (30 seconds)
- Tasks marked as failed
- Tasks requeued for retry
- Checkpoint data used for resume

**Database Failure:**
- PostgreSQL: Failover to replica (30 seconds)
- Cassandra: Quorum reads/writes continue
- Redis: Sentinel promotes replica (10 seconds)

## Component Interactions

### Task Submission Path

```python
# 1. Client submits task
POST /api/v1/tasks
{
  "name": "daily_report",
  "schedule": {"type": "once", "scheduled_time": "2024-02-01T00:00:00Z"}
}

# 2. API Server validates and persists
task_id = db.insert_task(task_definition)
kafka.produce("task-submissions", task_id)

# 3. Scheduler consumes and schedules
task = kafka.consume("task-submissions")
time_wheel.add_task(task, scheduled_time)

# 4. At scheduled time, move to execution queue
if current_time >= scheduled_time:
    redis.lpush("task-queue", task_id)

# 5. Worker polls and executes
task = redis.brpop("task-queue", timeout=30)
result = execute_task(task)
cassandra.insert_execution(task_id, result)
```

### Worker Heartbeat Flow

```python
# Worker sends heartbeat every 10 seconds
while True:
    heartbeat = {
        "worker_id": worker_id,
        "active_tasks": [task1, task2],
        "metrics": {"cpu": 60, "memory": 70}
    }
    redis.setex(f"worker:{worker_id}", 30, heartbeat)
    time.sleep(10)

# Scheduler monitors worker health
for worker_id in redis.keys("worker:*"):
    if not redis.exists(f"worker:{worker_id}"):
        # Worker failed, reassign tasks
        tasks = get_worker_tasks(worker_id)
        for task in tasks:
            redis.lpush("task-queue", task)
```

## Scaling Strategy

**Horizontal Scaling:**
- API Servers: Add more nodes behind load balancer
- Schedulers: Partition tasks by hash(task_id)
- Workers: Auto-scale based on queue depth

**Vertical Scaling:**
- Increase worker concurrency (more CPU cores)
- Larger Redis instances for queue
- More PostgreSQL connections

**Data Partitioning:**
- Kafka: Partition by task_type
- Cassandra: Partition by (task_id, execution_time)
- Redis: Separate queues per priority level

This architecture handles 10,000 task submissions/second, 100,000 concurrent executions, and provides 99.9% availability through redundancy and fault tolerance.
