# Latency & Percentiles (P50, P95, P99)

## Interview Focus

> **Master These Concepts:** Understanding latency and percentiles is crucial for designing responsive systems and setting realistic SLAs.

**Critical Interview Questions:**
- "What's the difference between `latency` and `throughput`?"
- "Why is `P99 latency` more important than average latency?"
- "How would you reduce API latency from `500ms` to `50ms`?"
- "Design a system with `<100ms` global latency requirements"
- "How do you set `SLA targets` using percentiles?"

---

## What is Latency?

> **Core Definition:** Time taken to process a single request from start to finish.

### Key Characteristics
- Measured in `time units` (milliseconds, microseconds)
- `Single request focus` (not about volume)
- `End-to-end measurement` (includes all processing steps)
- `User experience impact` (directly affects perceived performance)

### Latency vs Other Metrics
| Metric | Focus | Unit | Example |
|--------|-------|------|---------|
| **`Latency`** | Single request time | ms | 50ms API response |
| **`Throughput`** | Requests per time | QPS | 10,000 requests/sec |
| **`Bandwidth`** | Data transfer rate | Mbps | 1 Gbps network |
| **`Response Time`** | End-to-end user time | ms | 200ms page load |

---

## Types of Latency

### Network Latency

#### Geographic Distance
```
Same rack: <1ms
Same datacenter: 0.5-2ms
Same city: 1-5ms
Same country: 10-50ms
Same continent: 50-100ms
Cross-continent: 100-300ms
Satellite: 500-700ms
```

#### Real-World Examples
```
New York → London: 76ms
San Francisco → Tokyo: 115ms
Los Angeles → Sydney: 180ms
New York → Mumbai: 200ms
```

### Processing Latency

#### Compute Operations
```
CPU cache access: 1-10ns
RAM access: 100ns
CPU computation: 1-10ms
Complex algorithm: 10-100ms
Machine learning inference: 1-100ms
```

#### Storage Operations
```
L1 cache: 0.5ns
L2 cache: 7ns
RAM: 100ns
SSD random read: 150μs
SSD sequential read: 1ms
HDD seek: 10ms
HDD sequential read: 20ms
```

### Application Latency

#### Service Types
```
Simple API (CRUD): 1-50ms
Complex API (joins): 50-200ms
Search query: 10-500ms
Recommendation engine: 100-1000ms
Video transcoding: 1-60 seconds
ML model training: minutes to hours
```

#### Database Operations
```
Cache hit (Redis): 0.1-1ms
Simple query (indexed): 1-10ms
Complex query (joins): 10-100ms
Full table scan: 100ms-10s
Transaction commit: 1-50ms
```

---

## Understanding Latency Percentiles

> **Critical Understanding:** Percentiles show the latency value below which a certain percentage of requests fall.

### Why Percentiles Matter More Than Averages

#### The Problem with Averages
```
Sample latencies (ms): [10, 15, 20, 25, 30, 35, 40, 45, 50, 5000]

Average: 527ms (heavily skewed by one outlier)
Median (P50): 32.5ms (more representative)

The average suggests poor performance, but 90% of users 
experience <50ms latency. The average hides the real story.
```

#### User Experience Impact
```
With 1M daily users:
- P90 = 200ms → 100,000 users experience >200ms
- P95 = 500ms → 50,000 users experience >500ms
- P99 = 2s → 10,000 users experience >2s

Tail latency affects your most active users!
```

### Percentile Definitions
| Percentile | Meaning | User Impact | Example |
|------------|---------|-------------|---------|
| **`P50 (Median)`** | 50% of requests faster | Half of users | 50ms |
| **`P90`** | 90% of requests faster | 1 in 10 users affected | 150ms |
| **`P95`** | 95% of requests faster | 1 in 20 users affected | 300ms |
| **`P99`** | 99% of requests faster | 1 in 100 users affected | 800ms |
| **`P99.9`** | 99.9% of requests faster | 1 in 1000 users affected | 2000ms |

---

## Industry Latency & Percentile Targets

### Tech Giants' SLA Targets

#### Google Services
```
Google Search:
- P50: <50ms
- P95: <100ms
- P99: <200ms
- P99.9: <500ms

Gmail:
- P50: <100ms
- P95: <300ms
- P99: <1000ms
```

#### Facebook/Meta Services
```
Facebook News Feed:
- P50: <100ms
- P95: <200ms
- P99: <500ms
- P99.9: <2000ms

Instagram Feed:
- P50: <150ms
- P95: <400ms
- P99: <1000ms
```

#### Amazon Services
```
Amazon Product Pages:
- P50: <75ms
- P95: <150ms
- P99: <300ms
- P99.9: <1000ms

AWS API Gateway:
- P50: <10ms
- P95: <50ms
- P99: <100ms
```

#### Netflix Streaming
```
Video Start Time:
- P50: <1s
- P95: <3s
- P99: <5s
- P99.9: <10s

API Response Times:
- P50: <50ms
- P95: <200ms
- P99: <500ms
```

---

## Latency in Distributed Systems

### Multi-Service Latency

#### Serial Processing
```
User Request → API Gateway (10ms)
            → Auth Service (20ms)
            → Business Logic (50ms)
            → Database Query (80ms)
            → Response Processing (15ms)
            → Total: 175ms
```

#### Parallel Processing
```
User Request → API Gateway (10ms)
            → [
                 Auth Service (20ms)
                 User Profile (30ms)     } Max = 30ms
                 Preferences (25ms)
               ]
            → Business Logic (40ms)
            → Total: 80ms (10 + 30 + 40)
```

### Tail Latency Amplification

#### Fan-out Pattern
```
Single request → 10 downstream services
Each service: P99 = 100ms
Overall P99: ~1000ms (10x amplification)

Rule: P99_overall ≈ P99_individual × num_services
```

#### Retry Amplification
```
Base latency: 50ms
With 3 retries on timeout (1s):
- Success case: 50ms
- Failure case: 3 × 1000ms = 3000ms
- P99 can jump from 100ms to 3000ms
```

---

## What Causes Tail Latency?

### System-Level Causes
```
1. Garbage Collection Pauses:
   - Java GC can pause for 100ms-1s
   - Affects all requests during pause
   - Creates spikes in P99/P99.9

2. Resource Contention:
   - CPU scheduling delays
   - Memory allocation bottlenecks
   - Disk I/O queuing
   - Network buffer exhaustion

3. Cache Misses:
   - Cold cache scenarios
   - Cache eviction during high load
   - Thundering herd problems

4. Database Lock Contention:
   - Long-running transactions
   - Deadlock resolution
   - Index maintenance operations
```

### Network-Level Causes
```
1. Packet Loss and Retransmission:
   - TCP retransmission timeouts
   - Network congestion
   - Router buffer overflows

2. Load Balancer Issues:
   - Uneven load distribution
   - Health check failures
   - Connection pool exhaustion

3. Geographic Routing:
   - Suboptimal routing paths
   - CDN cache misses
   - DNS resolution delays
```

---

## Measuring Percentiles

### Measurement Techniques

#### Histogram-Based Approach
```
1. Define Buckets:
   [0-1ms, 1-5ms, 5-10ms, 10-50ms, 50-100ms, 
    100-500ms, 500ms-1s, 1s-5s, 5s+]

2. Count Requests per Bucket:
   Bucket 0-1ms: 10,000 requests
   Bucket 1-5ms: 50,000 requests
   Bucket 5-10ms: 30,000 requests
   ...

3. Calculate Percentiles:
   Total requests: 100,000
   P95 = 95,000th request falls in 50-100ms bucket
```

#### Sliding Window Approach
```
1. Keep Recent Measurements:
   - Store last 10,000 latency measurements
   - Use circular buffer for efficiency
   - Update as new measurements arrive

2. Calculate Percentiles:
   - Sort measurements (or use quantile algorithms)
   - Find value at percentile position
   - Update every minute/second
```

---

## Latency Optimization Strategies

### Reduce Network Latency

#### Geographic Distribution
```
✅ CDN edge servers closer to users
✅ Multi-region deployment
✅ DNS-based routing to nearest datacenter
✅ Anycast IP addressing
```

#### Connection Optimization
```
✅ HTTP/2 multiplexing
✅ Keep-alive connections
✅ Connection pooling
✅ Reduce DNS lookups
```

### Reduce Processing Latency

#### Caching Strategies
```
✅ In-memory caching (Redis, Memcached)
✅ Application-level caching
✅ Database query result caching
✅ CDN for static content
```

#### Algorithm Optimization
```
✅ Use efficient data structures
✅ Optimize database queries
✅ Implement lazy loading
✅ Precompute expensive operations
```

### Tail Latency Optimization

#### Reduce Variability
```
1. Eliminate GC Pauses:
   - Use low-latency GC algorithms
   - Tune heap sizes appropriately
   - Consider off-heap storage

2. Optimize Resource Usage:
   - Prevent CPU starvation
   - Use dedicated thread pools
   - Implement backpressure

3. Database Optimization:
   - Avoid long-running transactions
   - Implement query timeouts
   - Use connection pooling
   - Monitor lock contention
```

#### Implement Timeouts and Circuit Breakers
```
1. Request Timeouts:
   - Set aggressive timeouts (P95 + buffer)
   - Fail fast rather than wait
   - Implement retry with jitter

2. Circuit Breakers:
   - Open circuit on high error rates
   - Prevent cascade failures
   - Implement graceful degradation

3. Load Shedding:
   - Drop requests during overload
   - Prioritize important traffic
   - Implement admission control
```

---

## Setting SLAs with Percentiles

### SLA Design Principles

#### Percentile-Based SLAs
```
Good SLA Structure:
- P50 latency: <100ms (typical user experience)
- P95 latency: <300ms (most users satisfied)
- P99 latency: <1000ms (acceptable for edge cases)
- Availability: 99.9% (error budget)

Avoid:
- Average latency SLAs (hide problems)
- P100 (max) SLAs (impossible to guarantee)
- Too aggressive targets (expensive to achieve)
```

#### Error Budgets
```
99.9% availability = 0.1% error budget
- 43.2 minutes downtime per month
- Can be spent on:
  * Planned maintenance
  * Performance issues
  * System failures
  * Experiments and deployments
```

### SLA Monitoring and Alerting

#### Alert Thresholds
```
Tiered Alerting:
- Warning: P95 > 1.5x SLA for 5 minutes
- Critical: P95 > 2x SLA for 2 minutes
- Emergency: P99 > 5x SLA for 1 minute

Example for P95 < 200ms SLA:
- Warning: P95 > 300ms for 5 min
- Critical: P95 > 400ms for 2 min  
- Emergency: P99 > 1000ms for 1 min
```

---

## Interview Scenarios

### Scenario 1: API Latency Optimization
**Question**: "Your API latency increased from 50ms to 500ms. How do you investigate and fix it?"

**Answer Framework**:
```
1. Identify the problem:
   - Check monitoring dashboards
   - Look at P50, P95, P99 trends
   - Identify when degradation started

2. Investigate layers:
   - Application logs for errors
   - Database query performance
   - Network connectivity issues
   - Resource utilization (CPU, memory)

3. Common causes & fixes:
   - Database: Add indexes, optimize queries
   - Network: Check for packet loss, routing issues
   - Application: Profile code, fix memory leaks
   - Infrastructure: Scale up/out resources

4. Prevention:
   - Set up alerting on P95 latency
   - Regular performance testing
   - Capacity planning
```

### Scenario 2: Tail Latency Investigation
**Question**: "Your API has P50=50ms but P99=5s. Users are complaining about slow responses. How do you investigate and fix this?"

**Answer Framework**:
```
1. Problem Analysis:
   - Large gap between P50 and P99 indicates outliers
   - 1% of requests are 100x slower than median
   - Suggests systemic issues, not just load

2. Investigation Steps:
   - Enable distributed tracing (Jaeger/Zipkin)
   - Analyze slow request patterns
   - Check for GC pauses in application logs
   - Monitor database slow query logs
   - Review resource utilization during spikes

3. Common Root Causes:
   - Garbage collection pauses
   - Database lock contention
   - Cache stampede scenarios
   - Network timeouts and retries
   - Resource starvation (CPU/memory)

4. Solutions:
   - Implement request timeouts (500ms)
   - Add circuit breakers for dependencies
   - Optimize GC settings or use low-latency GC
   - Add connection pooling and query optimization
   - Implement load shedding during overload

5. Prevention:
   - Set up P99 alerting
   - Regular performance testing
   - Chaos engineering to find edge cases
   - Capacity planning with safety margins
```

### Scenario 3: Global Latency Requirements
**Question**: "Design a system serving users globally with <100ms latency requirement."

**Answer Framework**:
```
1. Geographic distribution:
   - Deploy in multiple regions (US, EU, APAC)
   - Use CDN for static content
   - DNS-based routing to nearest region

2. Data strategy:
   - Replicate read-only data globally
   - Cache frequently accessed data
   - Use eventual consistency where possible

3. Architecture:
   - Microservices for independent scaling
   - Async processing for heavy operations
   - Circuit breakers for fault tolerance

4. Optimization:
   - Connection pooling
   - HTTP/2 for multiplexing
   - Compression for large responses
```

---

## Practice Problems

> **Learn by Doing:** Work through these problems to master latency and percentile optimization.

### Problem 1: Percentile Analysis and SLA Setting

**Question**: "Analyze this latency distribution and set appropriate SLAs: [10ms×1000, 50ms×8000, 200ms×800, 1000ms×150, 5000ms×50 requests]"

**Your Task**: Calculate percentiles and design SLA structure.

**Hints**:
- Calculate `P50`, `P95`, `P99` from the distribution
- Consider `user impact` of different percentiles
- Design `realistic but ambitious` SLA targets

**Solution**:
```
1. Data Analysis:
   Total requests: 10,000
   Distribution:
   - 10ms: 1,000 requests (10%)
   - 50ms: 8,000 requests (80%) 
   - 200ms: 800 requests (8%)
   - 1000ms: 150 requests (1.5%)
   - 5000ms: 50 requests (0.5%)

2. Percentile Calculations:
   - P50 (5,000th request): 50ms
   - P90 (9,000th request): 50ms  
   - P95 (9,500th request): 200ms
   - P99 (9,900th request): 1000ms
   - P99.5 (9,950th request): 5000ms

3. Performance Assessment:
   - Good: 90% of users get 50ms response
   - Concerning: 5% wait 200ms+
   - Problem: 1% wait 1s+, 0.5% wait 5s+

4. Root Cause Analysis:
   - Bimodal distribution suggests two different code paths
   - 200ms group: Likely cache misses
   - 1000ms+ group: Database queries or external calls
   - 5000ms group: Timeouts or resource contention

5. SLA Recommendations:
   Current State SLAs:
   - P50: 50ms ✓ (good)
   - P95: 200ms (needs improvement)
   - P99: 1000ms (unacceptable)

   Target SLAs (after optimization):
   - P50: <50ms (maintain current performance)
   - P95: <100ms (optimize cache miss scenarios)
   - P99: <300ms (fix slow queries and timeouts)
   - Availability: 99.9%

6. Optimization Plan:
   - Implement caching to reduce 200ms responses
   - Add query optimization for 1000ms+ responses
   - Set 500ms timeout to eliminate 5000ms responses
   - Add circuit breakers and retry logic
```

---

### Problem 2: Database Latency Investigation

**Question**: "Your database queries went from 10ms P95 to 200ms P95. How do you investigate and fix this?"

**Your Task**: Systematically diagnose and resolve database performance issues.

**Hints**:
- Consider `query patterns` and `indexing`
- Think about `connection pooling` and `resource contention`
- Plan `monitoring` and `optimization` strategies

**Solution**:
```
1. Immediate Investigation:
   - Check slow query logs
   - Monitor active connections
   - Review recent schema changes
   - Check disk I/O and CPU utilization

2. Common Root Causes:
   - Missing indexes on new queries
   - Lock contention from long transactions
   - Connection pool exhaustion
   - Disk space or memory issues

3. Diagnostic Steps:
   - EXPLAIN ANALYZE slow queries
   - Monitor connection pool metrics
   - Check for blocking queries
   - Review query execution plans

4. Solutions:
   - Add missing indexes
   - Optimize query joins
   - Increase connection pool size
   - Implement query timeouts
   - Add read replicas for read-heavy workloads

5. Prevention:
   - Query performance testing in CI/CD
   - Regular index maintenance
   - Connection pool monitoring
   - Capacity planning for growth
```

---

## Related Topics for Deep Dive
- Capacity Planning & Back-of-the-Envelope Estimation
- Throughput Optimization
- Bandwidth Planning
- Response Time Optimization
- Performance Metrics
- Fault Tolerance and Reliability
- Load Balancing Strategies
- Caching Architectures
- Database Performance Tuning
- Distributed Tracing

---

## References

> **Deep Dive Resources:** Essential reading for mastering latency optimization and percentile analysis.

### Performance Numbers & Latency
| Resource | Description |
|----------|-------------|
| [Latency Numbers Every Programmer Should Know](https://gist.github.com/jboner/2841832) | Essential latency benchmarks |
| [The Tail at Scale](https://research.google/pubs/pub40801/) | Google's seminal paper on tail latency |
| [High Performance Browser Networking](https://hpbn.co/) | Network latency fundamentals |

### Percentiles and SLA Design
| Resource | Description |
|----------|-------------|
| [Site Reliability Engineering](https://sre.google/sre-book/service-level-objectives/) | Google's approach to SLOs and error budgets |
| [Percentiles in Practice](https://www.elastic.co/blog/averages-can-dangerous-use-percentile) | Why percentiles matter more than averages |
| [HdrHistogram Documentation](http://hdrhistogram.org/) | High-precision percentile measurement |

### Tools & Implementation
| Resource | Description |
|----------|-------------|
| [Distributed Tracing with Jaeger](https://www.jaegertracing.io/docs/) | End-to-end latency tracking |
| [Prometheus Percentiles](https://prometheus.io/docs/practices/histograms/) | Histogram-based percentile calculation |
| [Load Testing with k6](https://k6.io/docs/) | Latency testing under load |

---