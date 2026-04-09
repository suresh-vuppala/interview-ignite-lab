## Design Constraints That Drive Our Architecture

Our capacity calculations reveal critical design decisions that shape the entire system architecture.

## Constraint 1: Task Submission Volume → Message Queue Required

**Given:**
- 10 million tasks/day = 116 tasks/second average
- Peak load: 10,000 tasks/second (100x average)
- Task submission latency requirement: < 100ms (p99)

**Design Decision:**
```
Peak submission rate of 10,000 tasks/sec means:
- Direct database writes would bottleneck (typical DB: 5,000 writes/sec)
- Need message queue to buffer submissions
- Queue must handle 10,000 writes/sec + 10,000 reads/sec = 20,000 ops/sec

Technology choice: Kafka or RabbitMQ
- Kafka: 100,000+ messages/sec per partition
- RabbitMQ: 20,000+ messages/sec per queue
```

**Architectural Impact:**
- Decouple task submission from scheduling
- Async processing pipeline
- Horizontal scaling of submission API

## Constraint 2: Concurrent Execution → Worker Pool Architecture

**Given:**
- 100,000 tasks executing concurrently
- Average task duration: 30 seconds to 5 minutes
- Task execution throughput: 100,000 tasks/second

**Design Decision:**
```
100,000 concurrent tasks with 2-minute average duration:
- If 1 worker handles 10 concurrent tasks → Need 10,000 workers
- If 1 worker handles 50 concurrent tasks → Need 2,000 workers

Worker capacity calculation:
- CPU-bound tasks: 1-2x CPU cores
- I/O-bound tasks: 10-50x CPU cores
- Mixed workload: 20 concurrent tasks per worker (8-core machine)

Final: 5,000 workers (with 50% headroom for spikes)
```

**Architectural Impact:**
- Distributed worker pool with auto-scaling
- Task queue must support 5,000 concurrent consumers
- Need worker health monitoring and task reassignment

## Constraint 3: Scheduling Accuracy → Time-Wheel Algorithm

**Given:**
- Scheduling accuracy: ±1 second
- 10 million tasks scheduled per day
- Tasks distributed across 24 hours

**Design Decision:**
```
Naive approach: Check all tasks every second
- 10M tasks × 1 check/sec = 10M operations/sec ❌ Too expensive

Time-wheel approach: Bucket tasks by execution time
- 1-second buckets for next 1 hour = 3,600 buckets
- 1-minute buckets for next 24 hours = 1,440 buckets
- 1-hour buckets for next 30 days = 720 buckets

Average tasks per second: 116 tasks/sec
- Only check ~116 tasks per second ✓ Efficient
```

**Architectural Impact:**
- Multi-level time-wheel data structure
- Lazy loading of far-future tasks
- In-memory scheduling for near-term tasks

## Constraint 4: Storage Requirements → Hybrid Storage Strategy

**Given:**
- 100 million total tasks in system
- Task definition: ~2 KB per task
- Task instance: ~1 KB per execution
- Retention: 30 days of execution history

**Design Decision:**
```
Task Definitions (active):
- 10M active tasks × 2 KB = 20 GB
- Store in: PostgreSQL (ACID, queryable)

Task Instances (executions):
- 10M tasks/day × 30 days = 300M instances
- 300M × 1 KB = 300 GB
- Store in: Time-series DB (Cassandra/TimescaleDB)

Task Queue (pending):
- 100K concurrent × 1 KB = 100 MB
- Store in: Redis (in-memory, fast)

Total storage: ~320 GB (with indexes: ~500 GB)
```

**Architectural Impact:**
- PostgreSQL for task definitions (strong consistency)
- Cassandra for execution history (high write throughput)
- Redis for active task queue (low latency)

## Constraint 5: Network Bandwidth → Regional Deployment

**Given:**
- 10,000 task submissions/sec
- Average task payload: 2 KB
- 100,000 task executions/sec
- Average result: 1 KB

**Design Decision:**
```
Ingress (task submissions):
- 10,000 tasks/sec × 2 KB = 20 MB/sec = 160 Mbps

Egress (task distribution to workers):
- 100,000 tasks/sec × 2 KB = 200 MB/sec = 1.6 Gbps

Internal communication (status updates):
- 100,000 updates/sec × 500 bytes = 50 MB/sec = 400 Mbps

Total bandwidth: ~2.2 Gbps

Single datacenter: ✓ Feasible (10 Gbps links)
Multi-region: Need regional schedulers to reduce cross-region traffic
```

**Architectural Impact:**
- Deploy schedulers in same region as workers
- Use regional task queues
- Replicate task definitions across regions

## Constraint 6: Database Load → Read Replicas Required

**Given:**
- 50,000 status queries/second
- Task submission: 10,000 writes/second
- Worker heartbeats: 5,000 updates/second (5,000 workers × 1/sec)

**Design Decision:**
```
Write load:
- 10,000 task submissions/sec
- 5,000 heartbeat updates/sec
- 100,000 status updates/sec (task state changes)
- Total: 115,000 writes/sec

Single PostgreSQL: ~10,000 writes/sec ❌ Insufficient

Solution: Partition writes
- Task submissions → Message queue → Batch insert (10,000/sec)
- Status updates → Cassandra (100,000/sec)
- Heartbeats → Redis (5,000/sec)

Read load:
- 50,000 status queries/sec
- Single PostgreSQL: ~50,000 reads/sec ✓ Feasible with caching

Solution: Redis cache + PostgreSQL read replicas
- Cache hit rate: 80% → 10,000 DB queries/sec
- 3 read replicas handle 10,000 queries/sec
```

**Architectural Impact:**
- Write path: Queue → Batch processor → Database
- Read path: Cache → Read replica → Primary
- Separate databases for different access patterns

## Constraint 7: Failure Recovery → Checkpoint-Based Recovery

**Given:**
- 100,000 tasks executing concurrently
- Worker failure rate: 1% per hour
- Task timeout: 5 minutes average

**Design Decision:**
```
Worker failures per hour:
- 5,000 workers × 1% = 50 worker failures/hour

Tasks affected per failure:
- 50 failures × 20 tasks/worker = 1,000 tasks/hour need reassignment

Recovery time requirement:
- Detect failure: 30 seconds (3 missed heartbeats)
- Reassign tasks: 10 seconds
- Total: 40 seconds

Checkpoint strategy:
- Checkpoint task state every 30 seconds
- On failure, resume from last checkpoint
- Reduces wasted work by 50%
```

**Architectural Impact:**
- Worker heartbeat every 10 seconds
- Task state checkpointing
- Fast task reassignment queue
- Idempotency for task retries

## Constraint 8: Cost Optimization → Spot Instances for Workers

**Given:**
- 5,000 workers running 24/7
- Average CPU utilization: 60%
- On-demand cost: $0.10/hour per instance
- Spot instance cost: $0.03/hour per instance

**Design Decision:**
```
Annual cost comparison:
- On-demand: 5,000 × $0.10 × 24 × 365 = $4.38M/year
- Spot (70% spot, 30% on-demand): 
  - Spot: 3,500 × $0.03 × 24 × 365 = $920K/year
  - On-demand: 1,500 × $0.10 × 24 × 365 = $1.31M/year
  - Total: $2.23M/year (49% savings)

Spot instance interruption rate: ~5% per hour
- 3,500 spot workers × 5% = 175 interruptions/hour
- Need graceful task migration on interruption
```

**Architectural Impact:**
- Mix of spot and on-demand workers
- Graceful shutdown on spot interruption
- Task migration before worker termination
- Priority tasks on on-demand instances

## Summary: Design Decisions Driven by Scale

| Constraint | Calculation | Design Decision |
|------------|-------------|-----------------|
| **Submission Rate** | 10K tasks/sec peak | Message queue (Kafka) |
| **Concurrent Execution** | 100K concurrent tasks | 5,000 workers (20 tasks each) |
| **Scheduling Accuracy** | ±1 second | Time-wheel algorithm |
| **Storage** | 320 GB total | Hybrid: PostgreSQL + Cassandra + Redis |
| **Network** | 2.2 Gbps | Regional deployment |
| **Database Load** | 115K writes/sec | Partitioned writes + read replicas |
| **Failure Recovery** | 1,000 tasks/hour | Checkpoint every 30 seconds |
| **Cost** | $4.38M/year | 70% spot instances |

## Infrastructure Summary

**Compute:**
- 5,000 worker nodes (8 cores, 16 GB RAM each)
- 100 scheduler nodes (4 cores, 8 GB RAM each)
- 50 API nodes (4 cores, 8 GB RAM each)

**Storage:**
- PostgreSQL cluster: 500 GB (task definitions)
- Cassandra cluster: 1 TB (execution history)
- Redis cluster: 200 GB (task queue + cache)

**Network:**
- 10 Gbps internal network
- 2.5 Gbps external bandwidth

**Cost Estimate:**
- Workers: $2.23M/year (spot + on-demand mix)
- Schedulers: $350K/year
- Storage: $200K/year
- Network: $150K/year
- **Total: ~$3M/year**

These calculations drive every architectural decision in the following lessons, from API design to failure handling strategies.
