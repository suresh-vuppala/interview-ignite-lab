## Problem Statement

Design a distributed job/task scheduler system that can execute millions of tasks reliably at specified times or intervals. The system should support one-time tasks, recurring tasks, task dependencies, priority-based execution, and handle failures gracefully.

**Real-world examples:**
- **Cron jobs** - System maintenance, backups, report generation
- **Airflow** - Data pipeline orchestration
- **Kubernetes CronJobs** - Container-based scheduled tasks
- **AWS EventBridge** - Event-driven task scheduling
- **Celery Beat** - Distributed task queue with scheduling

## Functional Requirements

### Core Features

**1. Task Scheduling**
- Schedule one-time tasks for future execution
- Schedule recurring tasks (cron-like expressions)
- Support immediate task execution
- Cancel scheduled tasks before execution
- Update task schedules

**2. Task Execution**
- Execute tasks at specified times (within acceptable delay)
- Execute tasks in priority order
- Support task dependencies (DAG - Directed Acyclic Graph)
- Execute tasks with configurable timeouts
- Support task parameters and context

**3. Task Management**
- Query task status (pending, running, completed, failed)
- Retrieve task execution history
- List scheduled tasks
- Pause/resume task execution
- Delete tasks

**4. Reliability**
- Retry failed tasks with configurable policies
- Handle worker failures gracefully
- Ensure exactly-once or at-least-once execution
- Persist task state for recovery

### Out of Scope (Clarify with Interviewer)

- Task result storage (assume external storage)
- Complex workflow orchestration (focus on scheduling)
- Real-time streaming tasks
- Task versioning and rollback
- Multi-tenancy and access control

## Non-Functional Requirements

### Scale Requirements

**Task Volume:**
- 10 million tasks scheduled per day
- 100,000 tasks executing concurrently
- Peak: 10,000 task submissions per second
- Average task duration: 30 seconds to 5 minutes

**System Size:**
- 1,000 worker nodes
- 100 scheduler nodes
- Support for 100 million total tasks in system

### Performance Requirements

**Latency:**
- Task submission: < 100ms (p99)
- Scheduling accuracy: ± 1 second for time-based tasks
- Task pickup latency: < 5 seconds after scheduled time
- Status query: < 50ms (p99)

**Throughput:**
- 10,000 task submissions/second
- 100,000 task executions/second
- 50,000 status queries/second

### Reliability Requirements

**Availability:**
- 99.9% uptime (8.76 hours downtime/year)
- No single point of failure
- Graceful degradation under load

**Durability:**
- Zero task loss after successful submission
- Persistent task state across system restarts
- Audit trail for all task executions

**Consistency:**
- Exactly-once execution for critical tasks
- At-least-once execution for idempotent tasks
- Eventual consistency for task status

### Other Requirements

**Scalability:**
- Horizontal scaling for schedulers and workers
- Auto-scaling based on queue depth
- Support for heterogeneous worker types

**Monitoring:**
- Task execution metrics (success rate, latency, throughput)
- Queue depth and lag monitoring
- Worker health and utilization
- Alert on task failures and system issues

## Core Entities

### Task Definition

```python
class TaskDefinition:
    task_id: str              # Unique identifier
    name: str                 # Human-readable name
    task_type: str            # Type of task (email, data_processing, etc.)
    payload: dict             # Task-specific parameters
    
    # Scheduling
    schedule_type: str        # 'once', 'recurring', 'cron'
    scheduled_time: datetime  # For one-time tasks
    cron_expression: str      # For recurring tasks (e.g., "0 0 * * *")
    timezone: str             # Timezone for scheduling
    
    # Execution
    priority: int             # 0-10, higher = more important
    timeout: int              # Max execution time (seconds)
    max_retries: int          # Number of retry attempts
    retry_delay: int          # Delay between retries (seconds)
    
    # Dependencies
    depends_on: List[str]     # Task IDs this task depends on
    
    # Metadata
    created_at: datetime
    created_by: str
    tags: dict
```

### Task Instance

```python
class TaskInstance:
    instance_id: str          # Unique execution instance
    task_id: str              # Reference to TaskDefinition
    
    # Execution state
    status: str               # pending, running, completed, failed, cancelled
    scheduled_time: datetime  # When task should run
    started_at: datetime      # When execution started
    completed_at: datetime    # When execution finished
    
    # Execution details
    worker_id: str            # Worker executing the task
    attempt_number: int       # Current retry attempt
    error_message: str        # Error details if failed
    result: dict              # Task execution result
    
    # Metadata
    created_at: datetime
    updated_at: datetime
```

### Worker

```python
class Worker:
    worker_id: str            # Unique worker identifier
    hostname: str             # Worker machine hostname
    ip_address: str           # Worker IP
    
    # Capabilities
    task_types: List[str]     # Types of tasks this worker can execute
    max_concurrent_tasks: int # Max parallel tasks
    
    # State
    status: str               # active, idle, busy, offline
    current_tasks: List[str]  # Currently executing task instances
    last_heartbeat: datetime  # Last health check
    
    # Metadata
    registered_at: datetime
    version: str              # Worker software version
```

## Key Design Considerations

### 1. Scheduling Accuracy vs. Throughput

**Trade-off:**
- Precise scheduling (checking every second) → High CPU overhead
- Coarse scheduling (checking every minute) → Poor accuracy

**Our approach:**
- Use time-wheel algorithm for efficient scheduling
- Bucket tasks by time slots (e.g., 1-second buckets)
- Lazy evaluation for far-future tasks

### 2. Execution Guarantees

**Options:**
- **At-most-once**: Fast but may lose tasks
- **At-least-once**: May execute tasks multiple times
- **Exactly-once**: Complex but ideal for non-idempotent tasks

**Our approach:**
- At-least-once by default (simpler, works for idempotent tasks)
- Exactly-once for critical tasks using distributed locks
- Idempotency keys for deduplication

### 3. Task Distribution

**Options:**
- **Push model**: Scheduler pushes tasks to workers
- **Pull model**: Workers pull tasks from queue

**Our approach:**
- Pull model for better load balancing
- Workers pull tasks based on their capacity
- Scheduler only manages task queue

### 4. Failure Handling

**Scenarios:**
- Worker crashes during task execution
- Scheduler crashes
- Network partitions
- Database failures

**Our approach:**
- Task timeout detection
- Worker heartbeat monitoring
- Task state persistence
- Automatic task reassignment

## Success Metrics

**Functional Metrics:**
- Task submission success rate: > 99.99%
- Scheduling accuracy: 95% within ±1 second
- Task execution success rate: > 99%

**Performance Metrics:**
- Task submission latency (p99): < 100ms
- Task pickup latency (p99): < 5 seconds
- Worker utilization: 70-80%

**Reliability Metrics:**
- System uptime: > 99.9%
- Task loss rate: < 0.01%
- Failed task retry success rate: > 90%

## Next Steps

With requirements defined, we'll proceed to:

1. **Capacity Estimation** - Calculate storage, compute, and network needs
2. **API Design** - Define interfaces for task submission and management
3. **High-Level Architecture** - Design system components and data flow
4. **Deep Dives** - Explore task queue, scheduling algorithms, and failure handling
