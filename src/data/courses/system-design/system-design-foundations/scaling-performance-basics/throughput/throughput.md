# Throughput

## Understanding System Capacity

> **Engineering Foundation:** Throughput determines how much load your system can handle and directly impacts infrastructure costs and user experience.

**Core Learning Goals:**
- Master throughput as a fundamental capacity metric
- Understand the relationship between throughput and system resources
- Learn to identify and eliminate throughput bottlenecks
- Build intuition for scaling strategies and trade-offs
- Develop skills for measuring and optimizing system capacity

---

## What Throughput Really Means

> **Engineering Reality:** Throughput is your system's ability to handle load - it determines costs, user experience, and business success.

### Definition and Impact
**Throughput**: Number of requests your system processes per unit time

**Why Engineers Must Master This**:
- **Cost optimization** - Higher throughput = fewer servers = lower costs
- **Capacity planning** - Determines infrastructure requirements
- **User experience** - Insufficient throughput causes errors and slowdowns
- **Business scaling** - Throughput limits directly constrain business growth

### Throughput Metrics in Practice
| Metric | What It Measures | Engineering Use | Real Example |
|--------|------------------|-----------------|-------------|
| **`QPS`** | Queries Per Second | API capacity | "Our search API handles 50K QPS" |
| **`TPS`** | Transactions Per Second | Database capacity | "Payment DB processes 10K TPS" |
| **`RPS`** | Requests Per Second | Web server capacity | "Nginx serves 100K RPS" |
| **`Mbps`** | Megabits Per Second | Network capacity | "CDN delivers 10 Gbps" |

---

## Throughput vs Latency

### Key Differences

#### Throughput (Volume)
```
Focus: How many requests can we process?
Unit: Requests per second
Example: "We can handle 10,000 API calls per second"
Optimization: Add more servers, parallel processing
```

#### Latency (Speed)
```
Focus: How fast can we process one request?
Unit: Milliseconds per request
Example: "Each API call takes 50ms to complete"
Optimization: Faster hardware, caching, algorithms
```

### Relationship Between Throughput and Latency

#### Little's Law
```
Throughput = Concurrent Users / Average Response Time

Example:
- 1,000 concurrent users
- 100ms average response time
- Throughput = 1,000 / 0.1s = 10,000 QPS
```

#### Trade-off Scenarios

**Scenario 1: High Throughput, High Latency**
```
Batch Processing System:
- Throughput: 100,000 jobs/hour
- Latency: 30 minutes per job
- Use case: Data analytics, ETL pipelines
```

**Scenario 2: Low Throughput, Low Latency**
```
Real-time Trading System:
- Throughput: 1,000 trades/second
- Latency: 1ms per trade
- Use case: High-frequency trading
```

**Scenario 3: Balanced**
```
Web Application:
- Throughput: 10,000 requests/second
- Latency: 100ms per request
- Use case: E-commerce, social media
```

---

## Throughput Scaling Patterns

### Linear Scaling

#### Characteristics
```
Throughput ∝ Number of servers

Example:
1 server: 1,000 QPS
2 servers: 2,000 QPS
4 servers: 4,000 QPS
8 servers: 8,000 QPS
```

#### When It Works
- `Stateless services` (web servers, API gateways)
- `CPU-bound workloads` with no shared resources
- `Embarrassingly parallel` problems

### Bottleneck-Limited Scaling

#### Characteristics
```
Throughput plateaus at bottleneck capacity

Example:
1 server + 1 DB: 1,000 QPS
2 servers + 1 DB: 1,500 QPS (DB bottleneck)
4 servers + 1 DB: 1,500 QPS (no improvement)
```

#### Common Bottlenecks
- `Database connections` (connection pool limit)
- `Shared cache` (Redis/Memcached capacity)
- `Network bandwidth` (1 Gbps limit)
- `External APIs` (rate limits)

### Degraded Scaling

#### Characteristics
```
Throughput decreases under high load

Example:
1 server: 1,000 QPS
2 servers: 1,800 QPS (coordination overhead)
4 servers: 3,200 QPS (contention increases)
8 servers: 5,000 QPS (diminishing returns)
```

#### Causes
- `Lock contention` in shared resources
- `Context switching` overhead
- `Network coordination` costs
- `Garbage collection` pauses

---

## Real-World Throughput Examples

### Industry Scale Examples

#### Google
```
Google Search: 8.5 billion queries/day = ~100,000 QPS average
Gmail: 1.8 billion users, ~50,000 QPS peak
YouTube: 2 billion hours watched/month = ~20,000 video starts/second
```

#### Facebook
```
News Feed: 2.9 billion users, ~500,000 QPS peak
Messenger: 1.3 billion users, ~100,000 messages/second
Instagram: 2 billion users, ~200,000 photo uploads/second
```

#### Amazon
```
AWS API Gateway: 10,000 QPS per account (default limit)
DynamoDB: 40,000 read/write capacity units per table
S3: 3,500 PUT/COPY/POST/DELETE, 5,500 GET/HEAD per prefix/second
```

#### Netflix
```
Streaming: 230 million subscribers, ~1 million video starts/second peak
Recommendations: ~500,000 QPS for personalization
Content Delivery: 15+ Tbps global bandwidth
```

### Industry Benchmarks

#### Database Systems
```
MySQL (single instance): 1,000-10,000 QPS
PostgreSQL (single instance): 1,000-15,000 QPS
MongoDB (single instance): 10,000-50,000 QPS
Redis (single instance): 100,000-1,000,000 QPS
Cassandra (cluster): 1,000,000+ QPS
```

#### Web Servers
```
Nginx: 50,000-100,000 concurrent connections
Apache: 10,000-50,000 concurrent connections
Node.js: 10,000-100,000 concurrent connections
Go HTTP server: 100,000+ concurrent connections
```

#### Message Queues
```
RabbitMQ: 10,000-50,000 messages/second
Apache Kafka: 1,000,000+ messages/second
AWS SQS: 3,000 messages/second (standard), 300 (FIFO)
Redis Pub/Sub: 1,000,000+ messages/second
```

---

## Throughput Optimization Strategies

### Horizontal Scaling

#### Load Balancing
```
[Client] → [Load Balancer] → [Server 1] (2,500 QPS)
                          → [Server 2] (2,500 QPS)
                          → [Server 3] (2,500 QPS)
                          → [Server 4] (2,500 QPS)
                          → Total: 10,000 QPS
```

#### Sharding/Partitioning
```
Users A-F → Shard 1 (3,000 QPS)
Users G-M → Shard 2 (3,000 QPS)
Users N-S → Shard 3 (3,000 QPS)
Users T-Z → Shard 4 (3,000 QPS)
Total: 12,000 QPS
```

### Vertical Scaling

#### Hardware Upgrades
```
CPU: 4 cores → 16 cores (4x throughput)
RAM: 16GB → 64GB (better caching)
Storage: HDD → NVMe SSD (10x I/O throughput)
Network: 1 Gbps → 10 Gbps (10x bandwidth)
```

### Caching Strategies

#### Cache Hit Rate Impact
```
No cache: 1,000 QPS (database limited)
90% cache hit: 10,000 QPS (10x improvement)
99% cache hit: 100,000 QPS (100x improvement)
99.9% cache hit: 1,000,000 QPS (1000x improvement)
```

#### Multi-Level Caching
```
L1: Application cache (100,000 QPS)
L2: Redis cluster (50,000 QPS)
L3: Database read replicas (10,000 QPS)
L4: Primary database (1,000 QPS)
```

### Asynchronous Processing

#### Queue-Based Architecture
```
Synchronous API: 1,000 QPS (limited by processing time)
Asynchronous API: 50,000 QPS (queue absorbs load)
Background workers: Process at sustainable rate
```

#### Event-Driven Architecture
```
Request → Immediate response (fast)
        → Event published to queue
        → Multiple consumers process event
        → High throughput, low latency
```

---

## Interview Scenarios

### Scenario 1: Design High-Throughput API
**Question**: "Design an API to handle 1 million requests per second."

**Answer Framework**:
```
1. Load Balancing:
   - Multiple load balancer instances
   - DNS round-robin for geographic distribution
   - Health checks and failover

2. Application Tier:
   - 1000 application servers (1000 QPS each)
   - Stateless design for easy scaling
   - Connection pooling

3. Caching Layer:
   - Redis cluster for hot data
   - CDN for static content
   - Application-level caching

4. Database Strategy:
   - Read replicas for read-heavy workloads
   - Sharding for write scaling
   - Eventual consistency where acceptable

5. Monitoring:
   - Real-time throughput metrics
   - Auto-scaling based on QPS
   - Circuit breakers for fault tolerance
```

### Scenario 2: Throughput Bottleneck Investigation
**Question**: "Your system handles 10K QPS but you need 50K QPS. How do you scale?"

**Answer Framework**:
```
1. Identify Bottlenecks:
   - Profile current system under load
   - Check CPU, memory, network, disk utilization
   - Analyze database query performance
   - Monitor external service dependencies

2. Scaling Strategy:
   - If CPU bound: Add more application servers
   - If memory bound: Optimize caching, add RAM
   - If I/O bound: Use faster storage, read replicas
   - If network bound: Upgrade bandwidth, use CDN

3. Architecture Changes:
   - Implement caching at multiple levels
   - Move to microservices for independent scaling
   - Use async processing for heavy operations
   - Optimize database queries and indexes

4. Testing:
   - Load testing at each scaling step
   - Monitor latency during throughput increases
   - Validate system stability under peak load
```

### Scenario 3: E-commerce Peak Traffic
**Question**: "Handle Black Friday traffic (10x normal throughput) for an e-commerce site."

**Answer Framework**:
```
1. Capacity Planning:
   - Normal: 5,000 QPS
   - Peak: 50,000 QPS
   - Safety margin: 75,000 QPS capacity

2. Auto-scaling Strategy:
   - Pre-scale before peak hours
   - Auto-scaling groups with fast scale-out
   - Database read replicas
   - CDN pre-warming

3. Performance Optimization:
   - Cache product catalog heavily
   - Optimize checkout flow
   - Use queue for order processing
   - Implement graceful degradation

4. Monitoring & Alerting:
   - Real-time throughput dashboards
   - Alerts on capacity thresholds
   - Business metrics (conversion rate)
   - Automated rollback procedures
```

---

## Throughput Measurement & Monitoring

### Key Metrics to Track

#### Application Metrics
```
• Requests per second (QPS)
• Successful requests per second
• Error rate percentage
• Request queue depth
```

#### Infrastructure Metrics
```
• CPU utilization per server
• Memory usage patterns
• Network throughput (Mbps)
• Disk I/O operations per second
```

#### Database Metrics
```
• Queries per second
• Connection pool utilization
• Transaction throughput
• Replication lag
```

### Load Testing Strategy

#### Gradual Load Increase
```
Step 1: 1,000 QPS (baseline)
Step 2: 5,000 QPS (5x increase)
Step 3: 10,000 QPS (10x increase)
Step 4: 20,000 QPS (find breaking point)
Step 5: Sustained load test (30 minutes)
```

#### Traffic Patterns
```
Constant load: Steady QPS for capacity testing
Spike testing: Sudden 10x increase
Gradual ramp: Slow increase over time
Soak testing: Extended duration at high load
```

---

## Practice Problems

> **Learn by Doing:** Work through these problems to master throughput optimization.

### Problem 1: Database Throughput Scaling

**Question**: "Your MySQL database handles 5,000 QPS but you need 50,000 QPS. Design a scaling strategy."

**Your Task**: Plan database scaling approach with specific techniques.

**Hints**:
- Consider `read vs write` patterns
- Think about `sharding` and `replication`
- Plan for `data consistency` requirements

**Solution**:
```
1. Current State Analysis:
   - Single MySQL instance: 5,000 QPS
   - Assume 80% reads, 20% writes
   - Read QPS: 4,000, Write QPS: 1,000

2. Scaling Strategy:
   
   Phase 1: Read Scaling (Target: 20,000 QPS)
   - Add 4 read replicas
   - Route reads to replicas (4,000 QPS each)
   - Master handles writes (1,000 QPS)
   - Total capacity: 16,000 read + 1,000 write = 17,000 QPS

   Phase 2: Write Scaling (Target: 50,000 QPS)
   - Implement sharding by user_id
   - 5 shards (10,000 QPS each)
   - Each shard: 1 master + 4 read replicas
   - Total capacity: 40,000 read + 10,000 write = 50,000 QPS

3. Implementation Details:
   - Use consistent hashing for sharding
   - Implement read/write splitting in application
   - Add connection pooling (100 connections per server)
   - Monitor replication lag (<1 second)

4. Monitoring:
   - QPS per shard and replica
   - Connection pool utilization
   - Replication lag monitoring
   - Query performance metrics
```

---

### Problem 2: API Gateway Throughput Design

**Question**: "Design an API gateway to handle 500,000 QPS with <10ms added latency."

**Your Task**: Design high-throughput, low-latency API gateway architecture.

**Hints**:
- Consider `load balancing` and `routing`
- Think about `caching` and `rate limiting`
- Plan for `monitoring` and `security`

**Solution**:
```
1. Architecture Design:
   
   Load Balancer Tier:
   - 10 load balancers (50,000 QPS each)
   - Geographic distribution (US, EU, APAC)
   - Health checks and automatic failover
   
   API Gateway Tier:
   - 100 gateway instances (5,000 QPS each)
   - Stateless design for easy scaling
   - Connection pooling to backend services

2. Performance Optimization:
   
   Caching Layer:
   - Redis cluster for API responses (1ms latency)
   - 95% cache hit rate for read operations
   - TTL-based cache invalidation
   
   Routing Optimization:
   - Pre-compiled routing rules
   - In-memory route lookup (<0.1ms)
   - Connection reuse to backend services

3. Latency Budget (10ms total):
   - Load balancer: 1ms
   - Routing logic: 0.5ms
   - Authentication: 2ms
   - Rate limiting: 0.5ms
   - Backend call: 5ms
   - Response processing: 1ms

4. Monitoring & Scaling:
   - Real-time QPS monitoring
   - Auto-scaling based on CPU (>70%)
   - Circuit breakers for backend protection
   - Distributed tracing for latency analysis
```

---

### Problem 3: Message Queue Throughput Optimization

**Question**: "Your Kafka cluster processes 100,000 messages/second but you need 1,000,000 messages/second. How do you scale?"

**Your Task**: Design Kafka scaling strategy for 10x throughput increase.

**Hints**:
- Consider `partitioning` and `replication`
- Think about `producer` and `consumer` optimization
- Plan for `data retention` and `storage`

**Solution**:
```
1. Current State Analysis:
   - Current: 100,000 messages/second
   - Target: 1,000,000 messages/second
   - Assume average message size: 1KB

2. Kafka Cluster Scaling:
   
   Broker Scaling:
   - Increase from 3 to 15 brokers
   - Each broker: 70,000 messages/second capacity
   - Total cluster capacity: 1,050,000 messages/second
   
   Partition Strategy:
   - Increase partitions from 10 to 100 per topic
   - Distribute partitions evenly across brokers
   - Use message key for consistent partitioning

3. Producer Optimization:
   - Batch size: 100KB (100 messages)
   - Compression: LZ4 (30% size reduction)
   - Async sending with callbacks
   - Connection pooling (10 connections per producer)

4. Consumer Optimization:
   - 100 consumer instances (10,000 messages/second each)
   - Consumer groups for parallel processing
   - Batch processing (1000 messages per batch)
   - Offset management optimization

5. Infrastructure:
   - NVMe SSDs for storage (high IOPS)
   - 10 Gbps network between brokers
   - Dedicated Kafka cluster (no resource sharing)
   - Monitoring with JMX metrics

6. Monitoring:
   - Messages per second per topic/partition
   - Consumer lag monitoring
   - Broker resource utilization
   - Network throughput metrics
```

---

## Related Topics for Deep Dive
- Capacity Planning & Back-of-the-Envelope Estimation
- Horizontal vs Vertical Scaling
- Latency & Percentiles (P50, P95, P99)
- Performance Metrics
- Bandwidth Planning
- Response Time Optimization
- Fault Tolerance and Reliability
- Load Balancing Strategies
- Caching Architectures
- Database Scaling Patterns

---

## References

> **Deep Dive Resources:** Essential reading for mastering throughput optimization.

### Performance & Scalability
| Resource | Description |
|----------|-------------|
| [Designing Data-Intensive Applications](https://dataintensive.net/) | Throughput in distributed systems |
| [High Scalability](http://highscalability.com/) | Real-world throughput case studies |
| [Systems Performance](http://www.brendangregg.com/systems-performance-2nd-edition-book.html) | Performance analysis methodology |

### Load Testing & Benchmarking
| Resource | Description |
|----------|-------------|
| [Load Testing with k6](https://k6.io/docs/) | Throughput testing strategies |
| [Apache Bench (ab)](https://httpd.apache.org/docs/2.4/programs/ab.html) | Simple throughput testing |
| [JMeter Performance Testing](https://jmeter.apache.org/usermanual/index.html) | Comprehensive load testing |

### Database & Message Queue Scaling
| Resource | Description |
|----------|-------------|
| [MySQL Performance Tuning](https://dev.mysql.com/doc/refman/8.0/en/optimization.html) | Database throughput optimization |
| [Kafka Performance Tuning](https://kafka.apache.org/documentation/#performance) | Message queue throughput |
| [Redis Performance](https://redis.io/topics/benchmarks) | In-memory database throughput |

---