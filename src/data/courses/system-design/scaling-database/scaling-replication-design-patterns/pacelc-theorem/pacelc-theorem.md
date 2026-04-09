The CAP theorem tells us that during a network partition, we must choose between Consistency and Availability. But what about normal operations when there's no partition? PACELC extends CAP to address this gap.

## Understanding PACELC

**PACELC** stands for:
- **P**artition: If there is a partition
- **A**vailability vs **C**onsistency: Choose between A or C
- **E**lse (no partition)
- **L**atency vs **C**onsistency: Choose between L or C

```
IF partition occurs:
    Choose between Availability (A) or Consistency (C)
ELSE (normal operation):
    Choose between Latency (L) or Consistency (C)
```

### Why PACELC Matters

CAP theorem only addresses failure scenarios (partitions). But systems spend 99.9% of their time in normal operation. PACELC helps us understand trade-offs during both failure and normal conditions.

```
System uptime: 99.9%
├─ Normal operation: 99.9% of time → Latency vs Consistency trade-off
└─ Partition: 0.1% of time → Availability vs Consistency trade-off
```

## The Four Categories

### PA/EL: Prioritize Availability and Latency

**During Partition:** Choose Availability  
**Normal Operation:** Choose Latency (lower consistency)

**Characteristics:**
- Fast responses always
- Eventual consistency
- Accept stale reads
- High throughput

**Example: DynamoDB (default configuration)**

```python
# Write to DynamoDB
dynamodb.put_item(
    TableName='users',
    Item={'user_id': '123', 'name': 'Alice', 'balance': 1000}
)
# Returns immediately, replicates asynchronously

# Read from DynamoDB (eventually consistent read)
response = dynamodb.get_item(
    TableName='users',
    Key={'user_id': '123'},
    ConsistentRead=False  # PA/EL: Fast but may be stale
)
# Returns in ~1ms, might not see latest write
```

**During Partition:**
```
Region A (primary) ─────X────── Region B (replica)
                   partition

Write to Region A: ✓ Succeeds (Available)
Read from Region B: ✓ Returns stale data (Available but inconsistent)
```

**Use Cases:**
- Social media feeds (Twitter timeline)
- Product catalogs (Amazon product listings)
- User profiles (LinkedIn profiles)
- Analytics dashboards
- Content delivery networks

### PA/EC: Prioritize Availability, but Consistency in Normal Operation

**During Partition:** Choose Availability  
**Normal Operation:** Choose Consistency (higher latency)

**Characteristics:**
- Strong consistency when healthy
- Degrades to eventual consistency during failures
- Balanced approach

**Example: Cassandra with Quorum Reads/Writes**

```python
# Normal operation: Quorum consistency
session.execute(
    "INSERT INTO users (id, name, balance) VALUES (123, 'Alice', 1000)",
    consistency_level=ConsistencyLevel.QUORUM  # Wait for majority
)
# Latency: ~10-50ms (waits for 2 of 3 replicas)

session.execute(
    "SELECT * FROM users WHERE id = 123",
    consistency_level=ConsistencyLevel.QUORUM
)
# Returns consistent data, higher latency
```

**During Partition:**
```
Node A ─────X────── Node B ─────X────── Node C
       partition           partition

Replication Factor: 3
Quorum: 2 nodes

Partition scenario:
- Node A isolated
- Nodes B and C can still form quorum
- Writes to B+C succeed (Available)
- Node A serves stale reads (Available but inconsistent)
```

**Use Cases:**
- E-commerce inventory (strong consistency normally, availability during outages)
- Session stores (consistent sessions, degrade gracefully)
- Distributed caches with strong consistency requirements

### PC/EL: Prioritize Consistency, but Latency in Normal Operation

**During Partition:** Choose Consistency  
**Normal Operation:** Choose Latency (eventual consistency)

**Characteristics:**
- Fast during normal operation
- Refuses requests during partitions
- Rare configuration

**Example: MongoDB with Read Preference Secondary**

```python
# Normal operation: Read from secondaries (fast, eventually consistent)
client = MongoClient(
    'mongodb://primary,secondary1,secondary2',
    readPreference='secondary'  # PC/EL: Fast reads from replicas
)

result = client.db.users.find_one({'_id': 123})
# Latency: ~5ms (reads from nearest secondary)
# May return slightly stale data
```

**During Partition:**
```
Primary ─────X────── Secondary1 ─────X────── Secondary2
        partition                partition

Write attempt:
- Primary isolated, cannot reach majority
- Write rejected (Consistent but not Available)

Read attempt:
- Secondaries cannot confirm primary is alive
- Reads rejected (Consistent but not Available)
```

**Use Cases:**
- Systems that can tolerate downtime but never inconsistency
- Financial audit logs (must be consistent, can be unavailable)
- Compliance systems

### PC/EC: Prioritize Consistency Always

**During Partition:** Choose Consistency  
**Normal Operation:** Choose Consistency (higher latency)

**Characteristics:**
- Strong consistency always
- Higher latency
- May become unavailable during partitions
- Linearizability guarantees

**Example: Google Spanner**

```sql
-- Spanner uses TrueTime for global consistency
BEGIN TRANSACTION;

-- Read with strong consistency
SELECT balance FROM accounts WHERE id = 123;
-- Latency: ~10-100ms (waits for global timestamp)

-- Write with strong consistency
UPDATE accounts SET balance = balance - 100 WHERE id = 123;

COMMIT;
-- Waits for commit timestamp across regions
-- Latency: ~50-200ms depending on geography
```

**During Partition:**
```
Region US ─────X────── Region EU ─────X────── Region ASIA
          partition              partition

Transaction spanning regions:
- Cannot achieve quorum
- Transaction aborted (Consistent but not Available)
- System refuses to serve inconsistent data
```

**Use Cases:**
- Banking transactions (account transfers)
- Stock trading systems
- Booking systems (airline seats, hotel rooms)
- Distributed databases requiring ACID guarantees

## Real-World System Classifications

### PA/EL Systems

**Cassandra (with eventual consistency)**
```python
# Configuration
consistency_level = ConsistencyLevel.ONE  # PA/EL

# Write
session.execute(
    "INSERT INTO products (id, name, price) VALUES (?, ?, ?)",
    (123, 'Laptop', 999),
    consistency_level=ConsistencyLevel.ONE
)
# Returns immediately after 1 replica acknowledges

# Read
session.execute(
    "SELECT * FROM products WHERE id = ?",
    (123,),
    consistency_level=ConsistencyLevel.ONE
)
# Returns from nearest replica, may be stale
```

**Trade-offs:**
- Latency: 1-5ms (very fast)
- Availability: 99.99%
- Consistency: Eventual (seconds to minutes)

**DynamoDB (default)**
```python
# Eventually consistent read (PA/EL)
response = dynamodb.get_item(
    TableName='products',
    Key={'product_id': '123'},
    ConsistentRead=False
)
# Latency: ~1-2ms
# May return stale data from replica
```

**Riak**
```erlang
% Configure for PA/EL
{n_val, 3},      % 3 replicas
{r, 1},          % Read from 1 replica (low latency)
{w, 1}           % Write to 1 replica (low latency)
```

### PA/EC Systems

**Cassandra (with quorum)**
```python
# Configuration for PA/EC
consistency_level = ConsistencyLevel.QUORUM

# Write
session.execute(
    "INSERT INTO orders (id, user_id, total) VALUES (?, ?, ?)",
    (456, 123, 99.99),
    consistency_level=ConsistencyLevel.QUORUM
)
# Waits for majority (2 of 3 replicas)
# Latency: 10-50ms

# During partition: Still available if majority reachable
```

**Trade-offs:**
- Latency: 10-50ms (moderate)
- Availability: 99.9% (degrades during partitions)
- Consistency: Strong during normal operation, eventual during partitions

**Cosmos DB (Session Consistency)**
```csharp
// Session consistency: PA/EC behavior
var client = new CosmosClient(
    connectionString,
    new CosmosClientOptions {
        ConsistencyLevel = ConsistencyLevel.Session
    }
);

// Reads within same session see own writes (consistent)
// Reads from other sessions may lag (available during partition)
```

### PC/EC Systems

**MongoDB (with majority read/write concern)**
```python
# Configuration for PC/EC
client = MongoClient(
    'mongodb://primary,secondary1,secondary2',
    readPreference='primary',
    readConcernLevel='majority',
    w='majority'
)

# Write
client.db.accounts.update_one(
    {'_id': 123},
    {'$inc': {'balance': -100}},
    write_concern=WriteConcern(w='majority')
)
# Waits for majority acknowledgment
# Latency: 10-100ms

# During partition: Unavailable if primary loses majority
```

**Trade-offs:**
- Latency: 10-100ms (higher)
- Availability: 99.5% (unavailable during partitions)
- Consistency: Strong always

**etcd / Consul**
```go
// etcd uses Raft consensus (PC/EC)
ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
defer cancel()

// Write with strong consistency
_, err := client.Put(ctx, "/config/feature_flag", "enabled")
// Waits for Raft consensus
// Latency: 10-50ms

// During partition: Unavailable if leader loses quorum
```

**Google Spanner**
```sql
-- PC/EC with global strong consistency
BEGIN TRANSACTION;

-- External consistency guarantee
SELECT * FROM inventory WHERE product_id = 123;
UPDATE inventory SET quantity = quantity - 1 WHERE product_id = 123;

COMMIT;
-- Latency: 50-200ms (cross-region)
-- Unavailable during partition affecting quorum
```

## Detailed Use Case Analysis

### Use Case 1: E-Commerce Platform

**Product Catalog (PA/EL)**
```python
# Product listings can be eventually consistent
# Users tolerate slightly stale prices/descriptions

class ProductCatalog:
    def get_product(self, product_id):
        # Read from nearest replica, no consistency guarantee
        return dynamodb.get_item(
            TableName='products',
            Key={'id': product_id},
            ConsistentRead=False  # PA/EL: Fast, may be stale
        )
        # Latency: 1-2ms
        # Stale data acceptable: Price shown might be old
```

**Inventory Management (PC/EC)**
```python
# Inventory must be consistent to prevent overselling
# But needs availability for purchases

class InventoryManager:
    def reserve_item(self, product_id, quantity):
        # Strong consistency to prevent overselling
        return mongodb.find_one_and_update(
            {'product_id': product_id, 'quantity': {'$gte': quantity}},
            {'$inc': {'quantity': -quantity}},
            write_concern=WriteConcern(w='majority'),
            read_concern=ReadConcern('majority')
        )
        # Latency: 10-50ms
        # During partition: May become unavailable
        # Trade-off: Better to show "out of stock" than oversell
```

**Order History (PA/EC)**
```python
# Order history should be consistent normally
# But can show stale data during outages

class OrderHistory:
    def get_orders(self, user_id):
        # Quorum read for consistency
        return cassandra.execute(
            "SELECT * FROM orders WHERE user_id = ?",
            (user_id,),
            consistency_level=ConsistencyLevel.QUORUM
        )
        # Latency: 10-30ms
        # During partition: Falls back to ONE (stale but available)
```

### Use Case 2: Social Media Platform

**News Feed (PA/EL)**
```python
# Feed can be eventually consistent
# Speed matters more than perfect accuracy

class NewsFeed:
    def get_feed(self, user_id):
        # Read from cache or nearest replica
        feed = redis.get(f'feed:{user_id}')
        if not feed:
            # Eventually consistent read from Cassandra
            feed = cassandra.execute(
                "SELECT * FROM feed WHERE user_id = ? LIMIT 50",
                (user_id,),
                consistency_level=ConsistencyLevel.ONE
            )
        return feed
        # Latency: 1-5ms
        # Stale posts acceptable: User won't notice 1-2 second delay
```

**Direct Messages (PC/EC)**
```python
# Messages must be consistent
# Users expect to see their sent messages immediately

class DirectMessages:
    def send_message(self, from_user, to_user, content):
        # Strong consistency for message delivery
        return mongodb.insert_one(
            {
                'from': from_user,
                'to': to_user,
                'content': content,
                'timestamp': datetime.utcnow()
            },
            write_concern=WriteConcern(w='majority')
        )
        # Latency: 10-50ms
        # During partition: May fail, user sees error
        # Trade-off: Better to fail than deliver duplicate messages
```

**Like Counts (PA/EL)**
```python
# Like counts can be approximate
# Speed and availability matter more

class LikeCounter:
    def increment_likes(self, post_id):
        # Asynchronous increment, no consistency guarantee
        redis.incr(f'likes:{post_id}')
        # Latency: <1ms
        # Count may be slightly off, acceptable for social metrics
        
        # Periodically sync to database
        asyncio.create_task(self.sync_to_db(post_id))
```

### Use Case 3: Banking System

**Account Balance (PC/EC)**
```python
# Account balance must be strongly consistent
# Cannot show incorrect balance or allow overdrafts

class AccountService:
    def transfer(self, from_account, to_account, amount):
        # Use distributed transaction with strong consistency
        with spanner.transaction() as txn:
            # Read with strong consistency
            from_balance = txn.execute_sql(
                "SELECT balance FROM accounts WHERE id = @id",
                params={'id': from_account}
            ).one()[0]
            
            if from_balance < amount:
                raise InsufficientFundsError()
            
            # Update both accounts atomically
            txn.execute_update(
                "UPDATE accounts SET balance = balance - @amount WHERE id = @id",
                params={'amount': amount, 'id': from_account}
            )
            txn.execute_update(
                "UPDATE accounts SET balance = balance + @amount WHERE id = @id",
                params={'amount': amount, 'id': to_account}
            )
        # Latency: 50-200ms
        # During partition: Transaction fails (unavailable)
        # Trade-off: Better to be unavailable than inconsistent
```

**Transaction History (PA/EC)**
```python
# Transaction history should be consistent
# But can tolerate brief unavailability

class TransactionHistory:
    def get_transactions(self, account_id, limit=100):
        # Read with quorum for consistency
        return cassandra.execute(
            "SELECT * FROM transactions WHERE account_id = ? LIMIT ?",
            (account_id, limit),
            consistency_level=ConsistencyLevel.QUORUM
        )
        # Latency: 10-50ms
        # During partition: May show cached/stale data
```

### Use Case 4: Ride-Sharing Platform

**Driver Location (PA/EL)**
```python
# Driver locations update frequently
# Approximate location acceptable

class DriverLocationService:
    def update_location(self, driver_id, lat, lon):
        # Write to nearest node, no consistency guarantee
        redis.geoadd(
            'drivers:locations',
            lon, lat, driver_id
        )
        # Latency: <1ms
        # Location may be slightly stale on other nodes
        
    def find_nearby_drivers(self, lat, lon, radius_km):
        # Read from nearest node
        return redis.georadius(
            'drivers:locations',
            lon, lat, radius_km, unit='km'
        )
        # Latency: 1-5ms
        # May miss some drivers or show slightly wrong positions
```

**Ride Matching (PC/EC)**
```python
# Ride assignment must be consistent
# Cannot assign same driver to multiple riders

class RideMatchingService:
    def assign_driver(self, ride_id, driver_id):
        # Atomic operation with strong consistency
        result = mongodb.find_one_and_update(
            {
                'driver_id': driver_id,
                'status': 'available'
            },
            {
                '$set': {
                    'status': 'assigned',
                    'ride_id': ride_id,
                    'assigned_at': datetime.utcnow()
                }
            },
            write_concern=WriteConcern(w='majority'),
            read_concern=ReadConcern('majority')
        )
        # Latency: 10-50ms
        # During partition: May fail, rider sees "no drivers available"
        # Trade-off: Better to fail than double-assign driver
```

**Pricing (PA/EL)**
```python
# Surge pricing can be eventually consistent
# Approximate pricing acceptable

class PricingService:
    def get_price_estimate(self, pickup, dropoff):
        # Read from cache or nearest node
        surge_multiplier = redis.get(f'surge:{pickup.zone}') or 1.0
        base_price = calculate_base_price(pickup, dropoff)
        return base_price * float(surge_multiplier)
        # Latency: 1-2ms
        # Surge multiplier may be slightly stale, acceptable
```

## Configuration Examples

### Cassandra Tuning

```python
# PA/EL Configuration
session.execute(
    query,
    consistency_level=ConsistencyLevel.ONE
)
# Latency: 1-5ms
# Availability: Very high
# Consistency: Eventual

# PA/EC Configuration
session.execute(
    query,
    consistency_level=ConsistencyLevel.QUORUM
)
# Latency: 10-50ms
# Availability: High (degrades during partition)
# Consistency: Strong normally, eventual during partition

# PC/EC Configuration
session.execute(
    query,
    consistency_level=ConsistencyLevel.ALL
)
# Latency: 20-100ms
# Availability: Lower (unavailable if any replica down)
# Consistency: Strong always
```

### DynamoDB Tuning

```python
# PA/EL: Eventually consistent reads (default)
response = dynamodb.get_item(
    TableName='table',
    Key={'id': '123'},
    ConsistentRead=False
)
# Latency: 1-2ms
# Cost: 0.5 RCU per read

# PC/EC: Strongly consistent reads
response = dynamodb.get_item(
    TableName='table',
    Key={'id': '123'},
    ConsistentRead=True
)
# Latency: 5-10ms
# Cost: 1 RCU per read (2x more expensive)
```

### MongoDB Tuning

```python
# PA/EL: Read from secondaries
client = MongoClient(
    read_preference=ReadPreference.SECONDARY_PREFERRED,
    read_concern=ReadConcern('local')
)
# Latency: 5-20ms
# May return stale data

# PC/EC: Read from primary with majority
client = MongoClient(
    read_preference=ReadPreference.PRIMARY,
    read_concern=ReadConcern('majority'),
    write_concern=WriteConcern(w='majority')
)
# Latency: 10-100ms
# Strong consistency
```

## Decision Framework

### Choose PA/EL When:

✅ **Low latency is critical** (< 5ms)  
✅ **High availability required** (99.99%+)  
✅ **Eventual consistency acceptable**  
✅ **Read-heavy workload**  
✅ **User-facing features** (feeds, recommendations)

❌ **Financial transactions**  
❌ **Inventory management**  
❌ **Booking systems**

### Choose PA/EC When:

✅ **Balance between consistency and availability**  
✅ **Can tolerate brief inconsistency during failures**  
✅ **Moderate latency acceptable** (10-50ms)  
✅ **Mixed read/write workload**

❌ **Strict ACID requirements**  
❌ **Cannot tolerate any inconsistency**

### Choose PC/EC When:

✅ **Strong consistency required**  
✅ **Can tolerate unavailability during partitions**  
✅ **Financial or critical data**  
✅ **ACID transactions needed**  
✅ **Regulatory compliance**

❌ **Need 99.99% availability**  
❌ **Latency-sensitive applications**  
❌ **Global distribution with low latency**

## Comparison Table

| System | Classification | Partition Behavior | Normal Latency | Use Case |
|--------|---------------|-------------------|----------------|----------|
| **DynamoDB** (default) | PA/EL | Available, stale reads | 1-2ms | Product catalogs, user profiles |
| **Cassandra** (ONE) | PA/EL | Available, stale reads | 1-5ms | Social feeds, metrics |
| **Cassandra** (QUORUM) | PA/EC | Available if majority up | 10-50ms | Session stores, caching |
| **Riak** (default) | PA/EL | Available, stale reads | 2-10ms | Content storage, logs |
| **MongoDB** (majority) | PC/EC | Unavailable if no majority | 10-100ms | User accounts, orders |
| **Spanner** | PC/EC | Unavailable during partition | 50-200ms | Banking, booking systems |
| **etcd** | PC/EC | Unavailable if no quorum | 10-50ms | Configuration, coordination |
| **PostgreSQL** (single) | PC/EC | Unavailable during failure | 1-10ms | Traditional RDBMS workloads |
| **Cosmos DB** (eventual) | PA/EL | Available, stale reads | 1-5ms | IoT telemetry, logs |
| **Cosmos DB** (strong) | PC/EC | Unavailable during partition | 10-100ms | Financial records |

## Key Takeaways

1. **PACELC extends CAP** by considering normal operation trade-offs (Latency vs Consistency)
2. **PA/EL systems** prioritize speed and availability (social media, catalogs)
3. **PC/EC systems** prioritize consistency (banking, booking)
4. **PA/EC systems** balance both (session stores, caching)
5. **Most systems are configurable** - choose consistency level per operation
6. **Different data needs different guarantees** - use multiple databases in same application
7. **Latency matters** - 99.9% of time is normal operation, not partitions
8. **Business requirements drive choice** - understand cost of inconsistency vs unavailability
