## Design-Driven Capacity Planning

Capacity estimation isn't just about math—it's about making informed design decisions. Each calculation reveals constraints that shape our architecture choices.

## Scale Requirements Drive Architecture

Let's establish our target scale and see how it influences design decisions:

### Target Scale Parameters
- **Peak requests per second**: 1,000,000 QPS
- **Read to write ratio**: 10:1 (typical for cache workloads)
- **Total unique keys**: 10 billion
- **Average value size**: 500 bytes
- **Availability target**: 99.9% uptime

**Key insight**: These numbers immediately tell us we need horizontal scaling—no single machine can handle 1M QPS or store 10B keys.

## Memory Constraints Shape Node Architecture

### Raw Data Calculation
```
Total keys: 10 billion
Average key size: 50 bytes
Average value size: 500 bytes
Raw data size = 10B × 550 bytes = 5.5 TB
```

**Design decision #1**: We need distributed storage—no single node has 5.5 TB of RAM.

### Memory Overhead Analysis

Redis-style caches have significant overhead:

```
Per-key overhead:
- Object headers: ~48 bytes
- Hash table pointers: ~24 bytes
- Expiry metadata: ~16 bytes
- Memory fragmentation: ~20% additional

Total per key: 550 + 88 = 638 bytes
With fragmentation: 638 × 1.2 = 766 bytes
Total memory needed: 10B × 766 bytes = 7.66 TB
```

**Design decision #2**: Memory optimization is critical—overhead is 39% of raw data!

### Node Sizing Strategy

**Option 1: Many Small Nodes**
- 64 GB RAM per node
- Nodes needed: 7,660 GB ÷ 64 GB = 120 nodes
- Pros: Lower blast radius, easier to replace
- Cons: More network hops, complex management

**Option 2: Fewer Large Nodes**
- 256 GB RAM per node  
- Nodes needed: 7,660 GB ÷ 256 GB = 30 nodes
- Pros: Fewer network partitions, simpler topology
- Cons: Higher blast radius, expensive nodes

**Chosen approach**: 200 GB nodes (middle ground)
- Nodes needed: 7,660 GB ÷ 200 GB = 39 primary nodes
- With 3x replication: 39 × 3 = 117 total nodes

**Why this choice**:
- Balances operational complexity with fault tolerance
- 200 GB instances are cost-effective sweet spot
- ~2.5% of data lost per node failure (acceptable)

## Performance Requirements Drive Replication

### QPS Distribution Analysis
```
Total QPS: 1,000,000
Read QPS: 909,091 (90.9%)
Write QPS: 90,909 (9.1%)

Per primary node:
Read QPS: 909,091 ÷ 39 = 23,310 reads/sec
Write QPS: 90,909 ÷ 39 = 2,331 writes/sec
```

**Design decision #3**: Single primary can handle the write load, but we need read replicas for read scaling.

### Replication Factor Decision

**1x replication (no replicas)**:
- Pro: Lowest cost, simplest
- Con: No fault tolerance, no read scaling
- Verdict: ❌ Unacceptable for 99.9% availability

**2x replication (1 replica)**:
- Pro: 50% cost reduction vs 3x
- Con: Single point of failure during maintenance
- Read capacity: 2x
- Verdict: ⚠️ Risky for production

**3x replication (2 replicas)**:
- Pro: Survives 1 node failure, 3x read capacity
- Con: 3x storage cost
- Read capacity: 3x (can serve 68K reads/sec per shard)
- Verdict: ✅ Chosen for balance of cost and reliability

**5x replication (4 replicas)**:
- Pro: Maximum fault tolerance
- Con: 5x storage cost, complex management
- Verdict: ❌ Overkill for cache use case

## Network Bandwidth Influences Protocol Choice

### Bandwidth Calculation
```
Average request size: 550 bytes
Average response size: 500 bytes (for reads)

Network traffic per primary:
Inbound: (23,310 + 2,331) × 550 bytes = 14.1 MB/sec
Outbound: 23,310 × 500 bytes = 11.7 MB/sec
Total: 25.8 MB/sec per primary

Network utilization: 25.8 MB/sec ÷ 1.25 GB/sec (10 Gbps) = 2.1%
```

**Design decision #4**: Network is not a bottleneck, but protocol efficiency still matters.

**Protocol choice implications**:
- HTTP/REST: ~500 bytes overhead per request = 19x bandwidth waste
- Binary protocol: ~20 bytes overhead per request = acceptable
- **Chosen**: Custom binary protocol (Redis RESP-style)

## CPU Requirements Validate Single-Threaded Design

### CPU Analysis
```
Operations per primary: 25,641 ops/sec
CPU cycles per operation:
- Simple GET: ~1,000 cycles
- Simple SET: ~2,000 cycles
- Weighted average: ~1,200 cycles

CPU requirement: 25,641 × 1,200 = 30.8M cycles/sec
CPU utilization: 30.8M ÷ 3B cycles/sec = 1% of one core
```

**Design decision #5**: Single-threaded event loop is sufficient—CPU is not the bottleneck.

**Architecture implications**:
- Redis-style single-threaded I/O loop works well
- No need for complex multi-threading
- Simplifies consistency and reduces lock contention

## Cost Analysis Drives Optimization Priorities

### Infrastructure Cost Breakdown
```
High-memory instances (200 GB RAM):
- Cost per node: ~$1,800/month
- 117 total nodes: $210,600/month
- Annual cost: ~$2.5 million

Network costs:
- Data transfer: ~$50/TB
- Monthly transfer: 1M QPS × 550 bytes × 2.6M seconds = 1.4 PB
- Network cost: $70,000/month

Total monthly cost: ~$280,000
Annual cost: ~$3.4 million
```

**Design decision #6**: Memory optimization has highest ROI.

**Optimization priorities**:
1. **Memory efficiency** (highest impact): Reduce overhead from 39% to 20%
2. **Compression** (medium impact): 30-40% size reduction for text data
3. **Reserved instances** (low complexity): 30-50% cost reduction
4. **Spot instances for replicas** (medium risk): 60-70% cost reduction

## Growth Planning Influences Sharding Strategy

### Growth Scenarios

**2x growth (2M QPS, 20B keys)**:
- Memory needed: 15.3 TB
- Additional nodes: +39 primaries (+78 replicas)
- Timeline: 12-18 months
- **Implication**: Need seamless horizontal scaling

**10x growth (10M QPS, 100B keys)**:
- Memory needed: 76.6 TB  
- Additional nodes: +351 primaries (+702 replicas)
- Timeline: 3-5 years
- **Implication**: Sharding strategy must handle 1000+ nodes

**Design decision #7**: Choose consistent hashing over range-based partitioning.

**Why consistent hashing**:
- Adding nodes only moves ~1/N of data (vs ~50% for mod-N hashing)
- Enables gradual scaling without service disruption
- Handles non-uniform key distributions better than range partitioning

## Availability Requirements Drive Failure Handling

### Availability Math
```
99.9% availability = 8.76 hours downtime/year
99.99% availability = 52.6 minutes downtime/year

With 39 primary nodes:
MTBF per node: 8760 hours (1 year)
Cluster MTBF: 8760 ÷ 39 = 225 hours (9.4 days)

Failover time budget: 8.76 hours ÷ (365 ÷ 9.4) = 13.4 minutes per incident
```

**Design decision #8**: Automatic failover must complete in <10 minutes.

**Failover requirements**:
- Failure detection: <30 seconds
- Replica promotion: <60 seconds  
- DNS/routing update: <120 seconds
- Client reconnection: <300 seconds
- Total: <8.5 minutes (within budget)

## Capacity Planning Summary

Our capacity analysis drives these key architectural decisions:

| Constraint | Design Decision | Rationale |
|------------|-----------------|----------|
| **5.5 TB data** | Horizontal sharding mandatory | No single node can store this much |
| **1M QPS** | Read replicas + load balancing | Single node caps at ~400K QPS |
| **39% memory overhead** | Memory optimization priority | Biggest cost optimization opportunity |
| **2.1% network usage** | Binary protocol acceptable | Network not bottleneck, but efficiency helps |
| **1% CPU usage** | Single-threaded design works | CPU not bottleneck, keep it simple |
| **$3.4M annual cost** | Reserved instances + optimization | Cost management critical at scale |
| **10x growth potential** | Consistent hashing required | Must scale without major rewrites |
| **99.9% availability** | <10 minute failover required | Automatic recovery essential |

These constraints and decisions form the foundation for our detailed architecture design in the following lessons.