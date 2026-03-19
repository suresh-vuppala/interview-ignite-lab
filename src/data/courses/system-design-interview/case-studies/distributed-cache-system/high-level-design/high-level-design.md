## Starting with Black Box Architecture

Let's begin with the simplest possible view of our distributed cache system and progressively add detail.

### Level 1: Single Black Box

```
┌─────────────────────────────────────┐
│                                     │
│         Distributed Cache           │
│                                     │
│  • GET key → value                  │
│  • SET key value → OK               │
│  • DEL key → OK                     │
│                                     │
└─────────────────────────────────────┘
           ↑                 ↓
    Client Requests    Cached Responses
```

**What this hides:**
- How data is distributed across nodes
- How failures are handled
- How consistency is maintained
- How memory is managed

### Level 2: Client-Server Separation

```
┌─────────────────┐         ┌─────────────────────────────────────┐
│                 │         │                                     │
│   Client Apps   │◄────────┤         Cache Cluster               │
│                 │         │                                     │
│ • Web Services  │         │  • Handles 1M+ QPS                 │
│ • Mobile Apps   │         │  • Stores 10B+ keys                │
│ • Microservices │         │  • Sub-millisecond latency         │
│                 │         │  • 99.9% availability               │
└─────────────────┘         └─────────────────────────────────────┘
```

**Key insight:** Clients don't need to know internal complexity - they just see a fast, reliable cache.

### Level 3: Load Distribution Layer

```
┌─────────────────┐         ┌─────────────────┐         ┌─────────────────────────────────────┐
│                 │         │                 │         │                                     │
│   Client Apps   │◄────────┤  Load Balancer  │◄────────┤         Cache Nodes                 │
│                 │         │                 │         │                                     │
│                 │         │ • Route requests│         │  Node 1  │  Node 2  │  Node 3      │
│                 │         │ • Health checks │         │          │          │              │
│                 │         │ • Failover      │         │  Shard A │  Shard B │  Shard C     │
└─────────────────┘         └─────────────────┘         └─────────────────────────────────────┘
```

**What we've added:**
- Load distribution mechanism
- Multiple cache nodes
- Basic fault tolerance

**What's still hidden:**
- How data is partitioned
- How nodes communicate
- How data is replicated

## Progressive Architecture Refinement

### Level 4: Data Partitioning Revealed

```
                                    ┌─────────────────┐
                                    │  Load Balancer  │
                                    │                 │
                                    │ • Consistent    │
                                    │   Hashing       │
                                    │ • Route by key  │
                                    └─────────┬───────┘
                                              │
                    ┌─────────────────────────┼─────────────────────────┐
                    │                         │                         │
                    ▼                         ▼                         ▼
        ┌─────────────────┐       ┌─────────────────┐       ┌─────────────────┐
        │   Shard 1       │       │   Shard 2       │       │   Shard 3       │
        │                 │       │                 │       │                 │
        │ Keys: A-F       │       │ Keys: G-M       │       │ Keys: N-Z       │
        │ Slots: 0-5460   │       │ Slots: 5461-    │       │ Slots: 10923-   │
        │                 │       │        10922    │       │        16383    │
        └─────────────────┘       └─────────────────┘       └─────────────────┘
```

**Key design decisions revealed:**
- **Partitioning strategy**: Consistent hashing with 16,384 slots
- **Data distribution**: Each shard owns a range of hash slots
- **Routing logic**: Load balancer computes `hash(key) % 16384` to find shard

### Level 5: Replication for High Availability

```
                                    ┌─────────────────┐
                                    │  Load Balancer  │
                                    └─────────┬───────┘
                                              │
                    ┌─────────────────────────┼─────────────────────────┐
                    │                         │                         │
                    ▼                         ▼                         ▼
        ┌─────────────────┐       ┌─────────────────┐       ┌─────────────────┐
        │   Shard 1       │       │   Shard 2       │       │   Shard 3       │
        │                 │       │                 │       │                 │
        │ ┌─────────────┐ │       │ ┌─────────────┐ │       │ ┌─────────────┐ │
        │ │ Primary 1   │ │       │ │ Primary 2   │ │       │ │ Primary 3   │ │
        │ │ (Read/Write)│ │       │ │ (Read/Write)│ │       │ │ (Read/Write)│ │
        │ └─────────────┘ │       │ └─────────────┘ │       │ └─────────────┘ │
        │        │        │       │        │        │       │        │        │
        │        ▼        │       │        ▼        │       │        ▼        │
        │ ┌─────────────┐ │       │ ┌─────────────┐ │       │ ┌─────────────┐ │
        │ │ Replica 1A  │ │       │ │ Replica 2A  │ │       │ │ Replica 3A  │ │
        │ │ (Read Only) │ │       │ │ (Read Only) │ │       │ │ (Read Only) │ │
        │ └─────────────┘ │       │ └─────────────┘ │       │ └─────────────┘ │
        │ ┌─────────────┐ │       │ ┌─────────────┐ │       │ ┌─────────────┐ │
        │ │ Replica 1B  │ │       │ │ Replica 2B  │ │       │ │ Replica 3B  │ │
        │ │ (Read Only) │ │       │ │ (Read Only) │ │       │ │ (Read Only) │ │
        │ └─────────────┘ │       │ └─────────────┘ │       │ └─────────────┘ │
        └─────────────────┘       └─────────────────┘       └─────────────────┘
```

**New components revealed:**
- **Primary-Replica architecture**: Each shard has 1 primary + 2 replicas
- **Write path**: All writes go to primary
- **Read path**: Reads can go to primary or replicas
- **Replication**: Async replication from primary to replicas

### Level 6: Complete System Architecture

```
┌─────────────────────────────────────────────────────────────────────────────────────┐
│                                   Client Layer                                      │
│                                                                                     │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐         │
│  │   Web App   │    │ Mobile App  │    │Microservice │    │   Admin     │         │
│  │             │    │             │    │             │    │   Tools     │         │
│  └─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘         │
└─────────────────────────────────────────┬───────────────────────────────────────────┘
                                          │
┌─────────────────────────────────────────┼───────────────────────────────────────────┐
│                              Proxy/Gateway Layer                                   │
│                                         │                                           │
│  ┌─────────────────────────────────────────────────────────────────────────────┐   │
│  │                        Load Balancer / API Gateway                         │   │
│  │                                                                             │   │
│  │  • Request routing (consistent hashing)                                    │   │
│  │  • Connection pooling                                                      │   │
│  │  • Authentication & authorization                                          │   │
│  │  • Rate limiting & throttling                                              │   │
│  │  • Circuit breakers                                                        │   │
│  │  • Monitoring & metrics collection                                         │   │
│  └─────────────────────────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────┬───────────────────────────────────────────┘
                                          │
┌─────────────────────────────────────────┼───────────────────────────────────────────┐
│                                Cache Cluster                                       │
│                                         │                                           │
│     ┌─────────────────┐       ┌─────────────────┐       ┌─────────────────┐       │
│     │   Shard 1       │       │   Shard 2       │       │   Shard N       │       │
│     │  Slots 0-5460   │       │ Slots 5461-10922│       │Slots 10923-16383│       │
│     │                 │       │                 │       │                 │       │
│     │ ┌─────────────┐ │       │ ┌─────────────┐ │       │ ┌─────────────┐ │       │
│     │ │ Primary     │ │       │ │ Primary     │ │       │ │ Primary     │ │       │
│     │ │ • Writes    │ │       │ │ • Writes    │ │       │ │ • Writes    │ │       │
│     │ │ • Reads     │ │       │ │ • Reads     │ │       │ │ • Reads     │ │       │
│     │ │ • Memory    │ │       │ │ • Memory    │ │       │ │ • Memory    │ │       │
│     │ │   Mgmt      │ │       │ │   Mgmt      │ │       │ │   Mgmt      │ │       │
│     │ └─────────────┘ │       │ └─────────────┘ │       │ └─────────────┘ │       │
│     │        │        │       │        │        │       │        │        │       │
│     │        ▼        │       │        ▼        │       │        ▼        │       │
│     │ ┌─────────────┐ │       │ ┌─────────────┐ │       │ ┌─────────────┐ │       │
│     │ │ Replica A   │ │       │ │ Replica A   │ │       │ │ Replica A   │ │       │
│     │ │ • Reads     │ │       │ │ • Reads     │ │       │ │ • Reads     │ │       │
│     │ │ • Failover  │ │       │ │ • Failover  │ │       │ │ • Failover  │ │       │
│     │ └─────────────┘ │       │ └─────────────┘ │       │ └─────────────┘ │       │
│     │ ┌─────────────┐ │       │ ┌─────────────┐ │       │ ┌─────────────┐ │       │
│     │ │ Replica B   │ │       │ │ Replica B   │ │       │ │ Replica B   │ │       │
│     │ │ • Reads     │ │       │ │ • Reads     │ │       │ │ • Reads     │ │       │
│     │ │ • Failover  │ │       │ │ • Failover  │ │       │ │ • Failover  │ │       │
│     │ └─────────────┘ │       │ └─────────────┘ │       │ └─────────────┘ │       │
│     └─────────────────┘       └─────────────────┘       └─────────────────┘       │
└─────────────────────────────────────────┬───────────────────────────────────────────┘
                                          │
┌─────────────────────────────────────────┼───────────────────────────────────────────┐
│                              Persistence Layer                                     │
│                                         │                                           │
│  ┌─────────────────────────────────────────────────────────────────────────────┐   │
│  │                           Backup & Recovery                                 │   │
│  │                                                                             │   │
│  │  • Periodic snapshots (RDB)                                                │   │
│  │  • Append-only logs (AOF)                                                  │   │
│  │  • Cross-region replication                                                │   │
│  │  • Object storage (S3/GCS)                                                 │   │
│  └─────────────────────────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────┬───────────────────────────────────────────┘
                                          │
┌─────────────────────────────────────────┼───────────────────────────────────────────┐
│                              Control Plane                                         │
│                                         │                                           │
│  ┌─────────────────────────────────────────────────────────────────────────────┐   │
│  │                      Cluster Management                                     │   │
│  │                                                                             │   │
│  │  • Node discovery & health monitoring                                      │   │
│  │  • Automatic failover orchestration                                        │   │
│  │  • Slot migration & rebalancing                                            │   │
│  │  • Configuration management                                                │   │
│  │  • Metrics collection & alerting                                           │   │
│  └─────────────────────────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────────────────────────────┘
```

## Data Flow Analysis

### Write Path Deep Dive

```
1. Client Request
   ┌─────────────────┐
   │ SET user:123    │
   │ "profile_data"  │
   └─────────┬───────┘
             │
2. Load Balancer
   ┌─────────┴───────┐
   │ hash("user:123")│
   │ = slot 7423     │
   │ → Shard 2       │
   └─────────┬───────┘
             │
3. Primary Node
   ┌─────────┴───────┐
   │ • Store in      │
   │   memory        │
   │ • Add to AOF    │
   │ • Return OK     │
   └─────────┬───────┘
             │
4. Async Replication
   ┌─────────┴───────┐
   │ • Send to       │
   │   Replica A     │
   │ • Send to       │
   │   Replica B     │
   └─────────────────┘
```

### Read Path Deep Dive

```
1. Client Request
   ┌─────────────────┐
   │ GET user:123    │
   └─────────┬───────┘
             │
2. Load Balancer
   ┌─────────┴───────┐
   │ hash("user:123")│
   │ = slot 7423     │
   │ → Shard 2       │
   │                 │
   │ Route to:       │
   │ • Primary (33%) │
   │ • Replica A(33%)│
   │ • Replica B(33%)│
   └─────────┬───────┘
             │
3. Selected Node
   ┌─────────┴───────┐
   │ • Check memory  │
   │ • Return value  │
   │   or nil        │
   └─────────────────┘
```

## Component Responsibilities

### Load Balancer/API Gateway
**Primary responsibilities:**
- Route requests to correct shard based on key hash
- Maintain connection pools to cache nodes
- Handle authentication and authorization
- Implement rate limiting and circuit breakers
- Collect metrics and health information

**Why it exists:**
- Clients shouldn't know about internal topology
- Provides single entry point for all cache operations
- Enables transparent failover and load distribution

### Cache Nodes (Primaries)
**Primary responsibilities:**
- Store key-value data in memory
- Handle write operations (SET, DEL, INCR)
- Serve read operations (GET, MGET)
- Manage memory and eviction policies
- Replicate changes to replica nodes

**Why primaries exist:**
- Single writer per shard ensures consistency
- Centralized memory management per shard
- Clear ownership of data partitions

### Cache Nodes (Replicas)
**Primary responsibilities:**
- Receive replication stream from primary
- Serve read operations to distribute load
- Stand ready for failover promotion
- Maintain synchronized copy of primary data

**Why replicas exist:**
- Increase read throughput (scale reads horizontally)
- Provide fault tolerance (survive primary failures)
- Enable zero-downtime maintenance

### Control Plane
**Primary responsibilities:**
- Monitor health of all nodes
- Orchestrate failover when nodes fail
- Manage slot migration during scaling
- Maintain cluster configuration
- Collect and aggregate metrics

**Why it exists:**
- Automate operational tasks
- Provide centralized cluster state management
- Enable self-healing capabilities

## Scaling Patterns

### Horizontal Scaling (Adding Nodes)

```
Before (3 shards):
┌─────────┐  ┌─────────┐  ┌─────────┐
│ Shard 1 │  │ Shard 2 │  │ Shard 3 │
│ 0-5460  │  │5461-10922│  │10923-   │
│         │  │         │  │  16383  │
└─────────┘  └─────────┘  └─────────┘

After (4 shards):
┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐
│ Shard 1 │  │ Shard 2 │  │ Shard 3 │  │ Shard 4 │
│ 0-4095  │  │4096-8191│  │8192-12287│  │12288-   │
│         │  │         │  │         │  │  16383  │
└─────────┘  └─────────┘  └─────────┘  └─────────┘
```

**Migration process:**
1. Add new shard with empty slots
2. Migrate slots from existing shards to new shard
3. Update routing table in load balancer
4. Clients automatically route to new topology

### Vertical Scaling (Upgrading Nodes)

```
Before:
┌─────────────────┐
│ Primary Node    │
│ • 100 GB RAM    │
│ • 16 CPU cores  │
│ • 25K QPS       │
└─────────────────┘

After:
┌─────────────────┐
│ Primary Node    │
│ • 200 GB RAM    │
│ • 32 CPU cores  │
│ • 50K QPS       │
└─────────────────┘
```

**Upgrade process:**
1. Promote replica to primary
2. Upgrade original primary hardware
3. Add upgraded node back as replica
4. Optionally promote back to primary

## Failure Scenarios and Responses

### Primary Node Failure

```
Normal State:
┌─────────────┐    ┌─────────────┐
│ Primary 1   │───▶│ Replica 1A  │
│ (Active)    │    │ (Standby)   │
└─────────────┘    └─────────────┘

After Failure:
┌─────────────┐    ┌─────────────┐
│ Primary 1   │    │ Replica 1A  │
│ (Failed)    │    │ (Promoted)  │
└─────────────┘    └─────────────┘
```

**Automatic response:**
1. Health checker detects primary failure
2. Control plane promotes best replica
3. Load balancer updates routing
4. New replica is provisioned

### Network Partition

```
Partition Scenario:
┌─────────────────────────┐    │    ┌─────────────────────────┐
│     Partition A         │    │    │     Partition B         │
│                         │    │    │                         │
│ ┌─────────┐ ┌─────────┐ │    │    │ ┌─────────┐             │
│ │Primary 1│ │Primary 2│ │    │    │ │Primary 3│             │
│ └─────────┘ └─────────┘ │    │    │ └─────────┘             │
│                         │    │    │                         │
│ ┌─────────┐             │    │    │ ┌─────────┐ ┌─────────┐ │
│ │Replica 3│             │    │    │ │Replica 1│ │Replica 2│ │
│ └─────────┘             │    │    │ └─────────┘ └─────────┘ │
└─────────────────────────┘    │    └─────────────────────────┘
```

**Response strategy:**
- Partition A: Has majority (3/5 nodes) → continues operating
- Partition B: Has minority (2/5 nodes) → enters read-only mode
- Prevents split-brain scenarios

This high-level architecture provides the foundation for understanding how all the detailed components we'll explore in subsequent lessons fit together to create a robust, scalable distributed cache system.