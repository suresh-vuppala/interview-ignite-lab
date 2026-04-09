## API Overview

Our job scheduler exposes RESTful APIs for task management and gRPC APIs for high-performance worker communication.

## Task Management APIs

### 1. Submit Task

**Endpoint:** `POST /api/v1/tasks`

**Purpose:** Schedule a new task for execution

**Request:**
```json
{
  "name": "daily_report_generation",
  "task_type": "report",
  "payload": {
    "report_type": "sales",
    "date_range": "2024-01-01:2024-01-31",
    "format": "pdf"
  },
  "schedule": {
    "type": "once",
    "scheduled_time": "2024-02-01T00:00:00Z",
    "timezone": "America/New_York"
  },
  "execution": {
    "priority": 5,
    "timeout": 300,
    "max_retries": 3,
    "retry_delay": 60
  },
  "dependencies": [],
  "tags": {
    "team": "analytics",
    "environment": "production"
  }
}
```

**Response:**
```json
{
  "task_id": "task_7f3a9b2c",
  "status": "pending",
  "scheduled_time": "2024-02-01T00:00:00Z",
  "created_at": "2024-01-15T10:30:00Z",
  "message": "Task scheduled successfully"
}
```

**Cron Expression Example:**
```json
{
  "schedule": {
    "type": "recurring",
    "cron_expression": "0 0 * * *",
    "timezone": "UTC"
  }
}
```

### 2. Get Task Status

**Endpoint:** `GET /api/v1/tasks/{task_id}`

**Response:**
```json
{
  "task_id": "task_7f3a9b2c",
  "name": "daily_report_generation",
  "status": "completed",
  "scheduled_time": "2024-02-01T00:00:00Z",
  "started_at": "2024-02-01T00:00:02Z",
  "completed_at": "2024-02-01T00:02:15Z",
  "worker_id": "worker_42",
  "attempt_number": 1,
  "result": {
    "output_file": "s3://reports/sales_2024_01.pdf",
    "rows_processed": 150000
  }
}
```

### 3. List Tasks

**Endpoint:** `GET /api/v1/tasks`

**Query Parameters:**
- `status`: Filter by status (pending, running, completed, failed)
- `task_type`: Filter by task type
- `from_time`: Start time range
- `to_time`: End time range
- `limit`: Page size (default: 100, max: 1000)
- `cursor`: Pagination cursor

**Response:**
```json
{
  "tasks": [
    {
      "task_id": "task_7f3a9b2c",
      "name": "daily_report_generation",
      "status": "completed",
      "scheduled_time": "2024-02-01T00:00:00Z"
    }
  ],
  "next_cursor": "eyJ0YXNrX2lkIjoidGFza183ZjNhOWIyYyJ9",
  "has_more": true
}
```

### 4. Cancel Task

**Endpoint:** `DELETE /api/v1/tasks/{task_id}`

**Response:**
```json
{
  "task_id": "task_7f3a9b2c",
  "status": "cancelled",
  "message": "Task cancelled successfully"
}
```

### 5. Update Task Schedule

**Endpoint:** `PATCH /api/v1/tasks/{task_id}/schedule`

**Request:**
```json
{
  "scheduled_time": "2024-02-02T00:00:00Z"
}
```

### 6. Get Task Execution History

**Endpoint:** `GET /api/v1/tasks/{task_id}/executions`

**Response:**
```json
{
  "task_id": "task_7f3a9b2c",
  "executions": [
    {
      "instance_id": "inst_abc123",
      "attempt_number": 1,
      "status": "completed",
      "started_at": "2024-02-01T00:00:02Z",
      "completed_at": "2024-02-01T00:02:15Z",
      "worker_id": "worker_42"
    },
    {
      "instance_id": "inst_def456",
      "attempt_number": 2,
      "status": "failed",
      "started_at": "2024-01-31T00:00:01Z",
      "completed_at": "2024-01-31T00:05:00Z",
      "error_message": "Connection timeout to database"
    }
  ]
}
```

## Worker Communication APIs (gRPC)

### 1. Poll for Tasks

**RPC:** `PollTasks`

**Request:**
```protobuf
message PollTasksRequest {
  string worker_id = 1;
  repeated string task_types = 2;  // Types this worker can handle
  int32 max_tasks = 3;              // Max tasks to fetch
  int32 timeout_seconds = 4;        // Long polling timeout
}
```

**Response:**
```protobuf
message PollTasksResponse {
  repeated Task tasks = 1;
}

message Task {
  string task_id = 1;
  string instance_id = 2;
  string task_type = 3;
  bytes payload = 4;
  int32 timeout = 5;
  int32 attempt_number = 6;
}
```

### 2. Update Task Status

**RPC:** `UpdateTaskStatus`

**Request:**
```protobuf
message UpdateTaskStatusRequest {
  string instance_id = 1;
  string worker_id = 2;
  TaskStatus status = 3;
  string error_message = 4;
  bytes result = 5;
  int64 progress_percentage = 6;
}

enum TaskStatus {
  RUNNING = 0;
  COMPLETED = 1;
  FAILED = 2;
}
```

### 3. Worker Heartbeat

**RPC:** `Heartbeat`

**Request:**
```protobuf
message HeartbeatRequest {
  string worker_id = 1;
  repeated string active_task_ids = 2;
  WorkerMetrics metrics = 3;
}

message WorkerMetrics {
  int32 cpu_usage_percent = 1;
  int32 memory_usage_percent = 2;
  int32 active_tasks = 3;
  int32 completed_tasks = 4;
}
```

**Response:**
```protobuf
message HeartbeatResponse {
  bool acknowledged = 1;
  repeated string tasks_to_cancel = 2;  // Tasks to abort
}
```

## Task Definition Schema

### Cron Expression Format

```
┌───────────── minute (0 - 59)
│ ┌───────────── hour (0 - 23)
│ │ ┌───────────── day of month (1 - 31)
│ │ │ ┌───────────── month (1 - 12)
│ │ │ │ ┌───────────── day of week (0 - 6) (Sunday to Saturday)
│ │ │ │ │
* * * * *

Examples:
- "0 0 * * *"     → Daily at midnight
- "*/15 * * * *"  → Every 15 minutes
- "0 9 * * 1-5"   → Weekdays at 9 AM
- "0 0 1 * *"     → First day of month at midnight
```

### Task Priority Levels

```python
class TaskPriority:
    CRITICAL = 10    # System-critical tasks
    HIGH = 7-9       # Important business tasks
    NORMAL = 4-6     # Regular tasks
    LOW = 1-3        # Background tasks
    BEST_EFFORT = 0  # Run when resources available
```

### Retry Policies

```json
{
  "retry_policy": {
    "max_retries": 3,
    "retry_delay": 60,
    "backoff_multiplier": 2.0,
    "max_retry_delay": 3600,
    "retry_on_errors": ["timeout", "connection_error"],
    "no_retry_on_errors": ["invalid_input", "authentication_failed"]
  }
}
```

## Task Dependencies (DAG)

### Define Task Dependencies

```json
{
  "task_id": "generate_report",
  "dependencies": [
    {
      "task_id": "extract_data",
      "wait_for_completion": true
    },
    {
      "task_id": "validate_data",
      "wait_for_completion": true
    }
  ]
}
```

### Dependency Resolution

```
Task Execution Order:

extract_data ──┐
               ├──> generate_report ──> send_email
validate_data ─┘

Rules:
1. Task starts only when all dependencies complete successfully
2. If any dependency fails, task is marked as "blocked"
3. Circular dependencies are rejected at submission time
```

## Batch Operations

### Bulk Task Submission

**Endpoint:** `POST /api/v1/tasks/batch`

**Request:**
```json
{
  "tasks": [
    {
      "name": "process_user_1",
      "task_type": "user_processing",
      "payload": {"user_id": 1}
    },
    {
      "name": "process_user_2",
      "task_type": "user_processing",
      "payload": {"user_id": 2}
    }
  ]
}
```

**Response:**
```json
{
  "submitted": 2,
  "failed": 0,
  "task_ids": ["task_abc", "task_def"]
}
```

## Idempotency

### Idempotency Key

```json
{
  "idempotency_key": "report_2024_01_31_v1",
  "name": "daily_report",
  "task_type": "report"
}
```

**Behavior:**
- Same idempotency key within 24 hours → Return existing task
- Prevents duplicate task submissions
- Stored in Redis with 24-hour TTL

## Rate Limiting

**Per-client limits:**
- 1,000 requests/minute for task submission
- 10,000 requests/minute for status queries
- Enforced using token bucket algorithm

**Response when rate limited:**
```json
{
  "error": "rate_limit_exceeded",
  "message": "Too many requests",
  "retry_after": 60
}
```

## Webhooks for Task Completion

### Register Webhook

```json
{
  "task_id": "task_7f3a9b2c",
  "webhook_url": "https://api.example.com/task-callback",
  "events": ["completed", "failed"]
}
```

### Webhook Payload

```json
{
  "event": "completed",
  "task_id": "task_7f3a9b2c",
  "instance_id": "inst_abc123",
  "status": "completed",
  "completed_at": "2024-02-01T00:02:15Z",
  "result": {
    "output_file": "s3://reports/sales_2024_01.pdf"
  }
}
```

## Error Handling

### Error Response Format

```json
{
  "error": {
    "code": "TASK_NOT_FOUND",
    "message": "Task with ID task_7f3a9b2c not found",
    "details": {
      "task_id": "task_7f3a9b2c"
    }
  }
}
```

### Common Error Codes

| Code | HTTP Status | Description |
|------|-------------|-------------|
| `TASK_NOT_FOUND` | 404 | Task does not exist |
| `INVALID_SCHEDULE` | 400 | Invalid cron expression or time |
| `CIRCULAR_DEPENDENCY` | 400 | Task dependencies form a cycle |
| `RATE_LIMIT_EXCEEDED` | 429 | Too many requests |
| `INTERNAL_ERROR` | 500 | Server error |

## API Design Principles

**1. Idempotency:**
- All write operations support idempotency keys
- Safe to retry failed requests

**2. Pagination:**
- Cursor-based pagination for large result sets
- Consistent ordering by task_id

**3. Filtering:**
- Support filtering by status, type, time range
- Efficient database queries with proper indexes

**4. Versioning:**
- API version in URL path (/api/v1/)
- Backward compatibility for 2 major versions

**5. Long Polling:**
- Workers use long polling (30-second timeout) to reduce network overhead
- Immediate response when tasks available

This API design supports our scale requirements of 10,000 task submissions/second and 50,000 status queries/second while maintaining simplicity and reliability.
