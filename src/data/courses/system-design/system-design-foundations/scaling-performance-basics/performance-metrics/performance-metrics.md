# Performance Metrics

## Understanding System Performance

> **Engineering Foundation:** Performance metrics are the language of system optimization and the key to building reliable, scalable systems.

**Core Learning Goals:**
- Master the fundamental performance metrics that drive engineering decisions
- Understand how to measure and interpret system behavior
- Learn to identify performance bottlenecks and optimization opportunities
- Build intuition for performance trade-offs in system design
- Develop skills for monitoring and improving production systems

---

## The Four Pillars of Performance

> **Engineering Reality:** These four metrics determine whether your system succeeds or fails in production.

### Essential Performance Metrics
| Metric | What It Measures | Why Engineers Care | Real-World Impact |
|--------|------------------|-------------------|-------------------|
| **`Latency`** | Time to process single request | User experience, SLA compliance | 100ms delay = 1% revenue loss |
| **`Throughput`** | Requests processed per unit time | System capacity, scaling needs | Determines infrastructure costs |
| **`Bandwidth`** | Data transfer capacity | Network bottlenecks, CDN needs | Affects global user experience |
| **`Response Time`** | End-to-end user experience | Business metrics, user retention | >3s load time = 53% user bounce |

### How These Metrics Drive Engineering Decisions
- **Architecture choices** - Microservices vs monolith based on latency requirements
- **Technology selection** - Database choice based on throughput needs
- **Infrastructure planning** - Server capacity based on performance targets
- **Optimization priorities** - Which bottlenecks to tackle first

---

## Latency: The User Experience Metric

> **Engineering Truth:** Latency is what users feel. Every millisecond matters for user satisfaction and business success.

### What Latency Really Means
**Definition**: The time it takes for a system to respond to a single request

**Why Engineers Must Care**: 
- **User perception** - Humans notice delays >100ms
- **Business impact** - Amazon found 100ms latency costs 1% of sales
- **System health** - High latency often indicates underlying problems
- **Cascading effects** - Slow services make everything downstream slower

### Latency in the Real World

#### Network Latency (Physics Limits)
```
Same datacenter: 0.5ms    (speed of light in fiber)
Same city: 5-10ms         (routing overhead)
Cross-country: 70ms       (3000 miles at light speed)
Cross-ocean: 150ms        (undersea cables)
Satellite: 600ms          (geostationary orbit)
```

#### Processing Latency (What You Can Control)
```
L1 cache: 0.5ns           (CPU cache hit)
RAM access: 100ns         (main memory)
SSD read: 150μs           (solid state storage)
HDD seek: 10ms            (mechanical disk)
Database query: 1-100ms   (depends on complexity)
API call: 10-200ms        (network + processing)
```

### Engineering Latency Budgets

#### How to Think About Latency
```
Total User Experience: 200ms
├── DNS lookup: 20ms
├── TCP connection: 30ms
├── TLS handshake: 50ms
├── HTTP request: 10ms
├── Server processing: 60ms
├── Database query: 20ms
└── Response transfer: 10ms
```

#### Real System Examples
```
Google Search: <100ms (P99)
- Why: Users expect instant results
- Impact: Every 100ms delay reduces searches by 0.6%

High-Frequency Trading: <1ms
- Why: Microseconds = millions of dollars
- Impact: Speed determines profitability

Video Games: <50ms
- Why: Human reaction time sensitivity
- Impact: Lag ruins competitive gaming
```

---

## Throughput: The Capacity Metric

> **Engineering Reality:** Throughput determines how much load your system can handle and directly impacts infrastructure costs.

### Understanding Throughput
**Definition**: The number of requests your system can process per unit time

**Why Engineers Need This**: 
- **Capacity planning** - How many servers do you need?
- **Cost optimization** - Higher throughput = fewer servers = lower costs
- **Scaling decisions** - When to scale horizontally vs vertically
- **Bottleneck identification** - Which component limits your system

### Throughput in Practice

#### Measuring Throughput
```
Queries Per Second (QPS):
- Small service: 100-1,000 QPS
- Medium service: 10,000-50,000 QPS  
- Large service: 100,000+ QPS
- Google Search: ~100,000 QPS average

Transactions Per Second (TPS):
- Payment systems: 1,000-10,000 TPS
- Stock exchanges: 100,000+ TPS
- Databases: 10,000-100,000 TPS
```

#### The Throughput-Latency Relationship
```
Little's Law: Throughput = Concurrent Users / Average Response Time

Practical Example:
- 1,000 concurrent users
- 100ms average response time  
- Throughput = 1,000 / 0.1s = 10,000 QPS

Engineering Insight:
- To double throughput: halve latency OR double concurrency
- But: higher concurrency often increases latency (queuing)
```

### Real-World Throughput Challenges

#### Scaling Patterns
```
Linear Scaling:
- Stateless services
- Well-designed databases
- Properly load-balanced systems

Bottleneck-Limited:
- Single database writer
- Shared cache
- External API dependencies

Degraded Performance:
- Memory pressure
- Lock contention
- Network saturation
```

---

## Bandwidth Deep Dive

> **Core Concept:** Maximum data transfer rate of a network connection.

### What is Bandwidth?
**Definition**: Maximum data transfer rate of a network connection

### Bandwidth Requirements by Service Type

#### Content Delivery
```
Text/API: 1-10 Mbps per 1000 users
Images: 100-500 Mbps per 1000 users
Video (HD): 1-5 Gbps per 1000 users
Video (4K): 10-25 Gbps per 1000 users
```

#### Real-World Examples
```
Netflix: 15+ Tbps global bandwidth
YouTube: 10+ Tbps global bandwidth
Facebook: 5+ Tbps global bandwidth
Amazon CloudFront: 100+ Tbps capacity
```

### Bandwidth Calculation

#### Formula
```
Bandwidth = QPS × Average Response Size

Example: Twitter Timeline
- 100,000 QPS
- 50KB average response
- Bandwidth = 100,000 × 50KB = 5 GB/s = 40 Gbps
```

---

## Response Time Deep Dive

> **Core Concept:** Total time from user action to complete response (includes network, processing, and rendering).

### What is Response Time?
**Definition**: Total time from user action to complete response (includes network, processing, and rendering)

### Response Time Components

#### Web Application
```
DNS Lookup: 20-120ms
TCP Connection: 20-100ms
TLS Handshake: 50-200ms
HTTP Request: 10-50ms
Server Processing: 50-500ms
HTTP Response: 10-100ms
Browser Rendering: 100-2000ms
```

#### Mobile Application
```
Network Request: 50-300ms
API Processing: 100-500ms
Data Parsing: 10-50ms
UI Rendering: 16-100ms (60 FPS = 16ms per frame)
```

### Response Time Targets

#### User Experience Guidelines
```
<100ms: Instant response (button clicks)
<300ms: Smooth interaction (page navigation)
<1000ms: Acceptable wait (search results)
<3000ms: Maximum tolerance (video loading)
>10000ms: User abandonment likely
```

---

## Latency Percentiles: P50, P95, P99

> **Critical Understanding:** Why percentiles matter more than averages for user experience.

### Why Percentiles Matter
- `Average latency` can hide outliers
- `Tail latency` affects user experience
- `SLA definitions` use percentiles

### Percentile Definitions

#### Common Percentiles
```
P50 (Median): 50% of requests faster than this
P90: 90% of requests faster than this
P95: 95% of requests faster than this
P99: 99% of requests faster than this
P99.9: 99.9% of requests faster than this
```

#### Example Distribution
```
API Response Times:
P50: 50ms   (half of users get <50ms)
P90: 150ms  (90% of users get <150ms)
P95: 300ms  (95% of users get <300ms)
P99: 800ms  (99% of users get <800ms)
P99.9: 2s   (99.9% of users get <2s)
```

### Industry Percentile Targets

#### Google Search
```
P50: <50ms
P95: <100ms
P99: <200ms
```

#### Facebook Feed
```
P50: <100ms
P95: <200ms
P99: <500ms
```

#### Amazon Product Page
```
P50: <75ms
P95: <150ms
P99: <300ms
```

### Tail Latency Impact

#### Why P99 Matters
```
With 1M daily users:
- P99 = 1s means 10,000 users wait >1s daily
- P99.9 = 2s means 1,000 users wait >2s daily

User experience impact:
- 1% of users = significant revenue impact
- Tail latency affects power users (most valuable)
```

---

## Fault vs Failure - Understanding Reliability

> **Critical Distinction:** Understanding the difference between faults and failures for system design.

### Definitions

#### Fault
- **Definition**: A defect or error in system component
- **Examples**: Disk failure, network packet loss, software bug
- **Impact**: May or may not cause system failure

#### Failure
- **Definition**: System unable to perform required function
- **Examples**: Service unavailable, data corruption, incorrect results
- **Impact**: User-visible problem

### Fault Tolerance vs Failure Prevention

#### Fault Tolerance
```
Goal: System continues operating despite faults
Techniques:
- Redundancy (multiple servers)
- Replication (data copies)
- Circuit breakers
- Graceful degradation
```

#### Failure Prevention
```
Goal: Prevent faults from occurring
Techniques:
- Code reviews
- Testing (unit, integration, chaos)
- Monitoring and alerting
- Capacity planning
```

### Reliability Metrics

#### Availability
```
Uptime / (Uptime + Downtime)

99.9% = 8.77 hours downtime/year
99.95% = 4.38 hours downtime/year
99.99% = 52.6 minutes downtime/year
99.999% = 5.26 minutes downtime/year
```

#### Mean Time Between Failures (MTBF)
```
MTBF = Total Operating Time / Number of Failures

Example:
- System runs 8760 hours/year
- 4 failures per year
- MTBF = 8760 / 4 = 2190 hours = 91 days
```

#### Mean Time To Recovery (MTTR)
```
MTTR = Total Downtime / Number of Failures

Example:
- 4 failures per year
- Total downtime: 2 hours
- MTTR = 2 hours / 4 = 30 minutes
```

---

## Performance Monitoring Strategy

### Key Metrics to Track

#### Application Metrics
```
• Request rate (QPS)
• Response time (P50, P95, P99)
• Error rate (%)
• Throughput (requests/second)
```

#### Infrastructure Metrics
```
• CPU utilization (%)
• Memory usage (%)
• Disk I/O (IOPS, latency)
• Network I/O (bandwidth, packets)
```

#### Business Metrics
```
• User engagement (DAU, session time)
• Conversion rate (%)
• Revenue impact ($)
• Customer satisfaction (NPS)
```

### Alerting Strategy

#### Alert Levels
```
P0 (Critical): Service down, data loss
P1 (High): Performance degradation >50%
P2 (Medium): Performance degradation 20-50%
P3 (Low): Trending toward issues
```

#### Alert Thresholds
```
Latency: P95 > 2x normal for 5 minutes
Error Rate: >1% for 2 minutes
Throughput: <50% normal for 5 minutes
Availability: <99.9% over 1 hour
```

---

## Engineering Case Studies

### Case Study 1: Netflix Video Streaming Performance
**Challenge**: Optimize video startup time for 200M+ users globally

> **Engineering Approach**: Systematic performance optimization across the entire stack

**Performance Analysis**:
```
1. Baseline Metrics:
   - Video start time: P95 = 8 seconds
   - Buffering events: 2.3 per session
   - CDN cache hit rate: 87%
   - User satisfaction: 3.2/5 stars

2. Root Cause Investigation:
   - CDN miss penalty: 4-6 seconds
   - Manifest parsing: 800ms
   - Initial segment fetch: 2-3 seconds
   - Client buffer initialization: 500ms

3. Engineering Solutions:
   - Predictive caching: Pre-load popular content
   - Manifest optimization: Reduce size by 60%
   - Parallel segment loading: 3x faster startup
   - Adaptive bitrate: Start low, scale up quickly

4. Results:
   - Video start time: P95 = 2.1 seconds (75% improvement)
   - Buffering events: 0.8 per session (65% reduction)
   - CDN cache hit rate: 94% (geographic optimization)
   - User satisfaction: 4.1/5 stars (business impact)
```

### Case Study 2: E-commerce Peak Traffic Optimization
**Challenge**: Handle Black Friday traffic (10x normal load) without degradation

> **Engineering Solution**: Performance-first architecture with graceful degradation

**System Design**:
```
1. Performance Requirements:
   - Maintain <200ms page load times
   - Handle 500K concurrent users
   - Keep error rate <0.1%
   - Ensure 99.99% uptime

2. Engineering Strategy:
   - Horizontal scaling: Auto-scale from 50 to 500 servers
   - Database optimization: Read replicas + connection pooling
   - Caching layers: Redis cluster + CDN
   - Load shedding: Graceful degradation for non-critical features

3. Monitoring Implementation:
   - Real-time dashboards: Latency, throughput, errors
   - Automated alerts: P95 latency >300ms triggers scaling
   - Business metrics: Revenue per minute tracking
   - Capacity monitoring: CPU, memory, database connections

4. Performance Results:
   - Peak QPS: 450K (vs 50K normal)
   - P95 latency: 180ms (maintained under load)
   - Error rate: 0.05% (well within SLA)
   - Revenue impact: 15% increase vs previous year
```

---

## Hands-On Performance Analysis

> **Learn by Doing:** Apply performance concepts to real engineering problems.

### Lab 1: API Performance Diagnosis

**Scenario**: Your API shows these metrics: P50=50ms, P95=200ms, P99=2000ms

**Engineering Challenge**: The large gap between P95 and P99 indicates a serious performance problem affecting 1% of users.

**Analysis Process**:
```
1. Problem Identification:
   - P99 is 10x slower than P95
   - 1% of users experience terrible performance
   - This suggests outlier behavior, not gradual degradation

2. Hypothesis Generation:
   - Garbage collection pauses (Java/C#)
   - Database lock contention
   - Cold cache misses
   - Network timeouts
   - Resource starvation (CPU/memory)

3. Investigation Tools:
   # Add distributed tracing
   curl -H "X-Trace-Id: $(uuidgen)" https://api.example.com/endpoint
   
   # Monitor GC metrics (Java)
   jstat -gc -t <pid> 1s
   
   # Check database slow queries
   SELECT * FROM pg_stat_statements ORDER BY mean_time DESC;
   
   # Analyze resource utilization
   top -p <pid>
   iostat 1

4. Engineering Solutions:
   - Circuit breakers: Fail fast on slow dependencies
   - Request timeouts: 500ms max for user-facing APIs
   - GC tuning: Reduce pause times
   - Connection pooling: Prevent connection exhaustion
   - Graceful degradation: Simplified responses under load
```

### Lab 2: Video Streaming Performance Design

**Challenge**: Design performance metrics for 10M concurrent video streams

**Engineering Requirements**:
```
1. User Experience Metrics:
   - Video start time: P95 < 3 seconds
   - Rebuffering ratio: < 0.5% of playback time
   - Video quality: Maximize bitrate within bandwidth
   - Completion rate: % of videos watched to end

2. Infrastructure Metrics:
   - CDN performance: Cache hit rate > 95%
   - Origin load: QPS and bandwidth utilization
   - Encoding pipeline: Processing time per video
   - Storage IOPS: For video file access

3. Business Impact Metrics:
   - Concurrent viewer capacity
   - Geographic performance distribution
   - Device-specific performance (mobile vs desktop)
   - Revenue correlation with performance

4. Monitoring Architecture:
   # Real-time metrics collection
   - Client-side: Video player telemetry
   - CDN: Edge server performance logs
   - Origin: Application and infrastructure metrics
   - Analytics: User behavior and business KPIs
   
   # Alerting strategy
   - P95 video start time > 4s: Page operations team
   - CDN cache hit rate < 90%: Alert CDN team
   - Concurrent viewers > 8M: Prepare for capacity scaling
```

### Lab 3: Database Performance Optimization

**Problem**: E-commerce database showing 5% error rate during peak traffic

**Engineering Analysis**:
```
1. Current State Assessment:
   - Good latency (100ms P50) but high errors (5%)
   - Errors indicate capacity limits, not code bugs
   - System is likely hitting resource constraints

2. Performance Investigation:
   # Database connection analysis
   SHOW PROCESSLIST;  -- MySQL
   SELECT * FROM pg_stat_activity;  -- PostgreSQL
   
   # Query performance analysis
   EXPLAIN ANALYZE SELECT ...;
   
   # Resource utilization
   iostat -x 1  -- Disk I/O
   free -h      -- Memory usage
   
3. Engineering Solutions:
   
   Immediate (< 1 hour):
   - Connection pooling: Limit concurrent connections
   - Query timeout: Prevent long-running queries
   - Read replicas: Distribute read load
   - Load shedding: Reject 1% of non-critical requests
   
   Short-term (< 1 week):
   - Index optimization: Add missing indexes
   - Query optimization: Rewrite slow queries
   - Caching layer: Redis for frequent queries
   - Vertical scaling: Increase CPU/memory
   
   Long-term (< 1 month):
   - Horizontal sharding: Distribute data
   - Microservices: Separate read/write workloads
   - Event sourcing: Async processing
   - Multi-region: Geographic distribution

4. Success Metrics:
   - Error rate: < 0.1%
   - P95 latency: < 200ms
   - Throughput: 2x current capacity
   - Cost efficiency: Performance per dollar
```

---

## Related Topics for Deep Dive
- Capacity Planning & Back-of-the-Envelope Estimation
- Horizontal vs Vertical Scaling
- Latency & Percentiles (P50, P95, P99)
- Bandwidth Planning
- Response Time Optimization
- Fault Tolerance and Reliability
- Load Balancing Strategies
- Caching Architectures
- Database Scaling Patterns
- Auto-scaling Policies

---

## References

> **Deep Dive Resources:** Essential reading for mastering performance metrics.

### Performance Numbers & Latency
| Resource | Description |
|----------|-------------|
| [Latency Numbers Every Programmer Should Know](https://gist.github.com/jboner/2841832) | Essential latency benchmarks |
| [High Performance Browser Networking](https://hpbn.co/) | Network performance fundamentals |
| [Systems Performance by Brendan Gregg](http://www.brendangregg.com/systems-performance-2nd-edition-book.html) | Comprehensive performance analysis |

### Monitoring & Observability
| Resource | Description |
|----------|-------------|
| [Google SRE Book - Monitoring](https://sre.google/sre-book/monitoring-distributed-systems/) | Monitoring distributed systems |
| [Prometheus Monitoring](https://prometheus.io/docs/introduction/overview/) | Metrics collection and alerting |
| [Distributed Tracing](https://opentracing.io/docs/overview/what-is-tracing/) | Request flow analysis |

### Industry Case Studies
| Resource | Description |
|----------|-------------|
| [Netflix Performance Engineering](https://netflixtechblog.com/performance-under-load-3e6fa9a60581) | Video streaming optimization |
| [Facebook Performance](https://engineering.fb.com/2021/03/10/networking-traffic/how-facebook-is-bringing-quic-to-billions/) | Social media scale performance |
| [Amazon Performance](https://aws.amazon.com/builders-library/timeouts-retries-and-backoff-with-jitter/) | E-commerce reliability patterns |

---