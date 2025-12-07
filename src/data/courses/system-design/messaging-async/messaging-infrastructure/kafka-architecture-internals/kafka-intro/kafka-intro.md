We've already covered kafka important terminologies in this post `core-messaging-concepts[Topics,Partitions,Producers, Consumers etc.]` [->](http://localhost:8080/course/system-design/api-layer/api-design-communication/http-fundamentals/http-methods)


<br>
`Apache Kafka` is a distributed event-streaming platform created by LinkedIn and later open sourced by the Apache Software Foundation. It’s built to handle large volumes of data in real time, enabling multiple applications to share and process data streams efficiently.

Unlike tools that process data in batches at set times, Kafka allows data to be processed continuously as it arrives, which is crucial in areas like e-commerce, IoT, social media, and finance.
<br>

# A real-world example of Kafka(UBER)
Consider a ride-hailing platform like Uber, where each ride generates a stream of updates: the driver’s location, trip status (e.g., started, ongoing, completed), and the estimated time of arrival (ETA).

These updates are placed in a queue by a process known as the producer. On the other side, another process called the consumer reads from this queue and performs its business logic.

https://blog.uber-cdn.com/wp-content/uploads/2022/08/Kafka-Consumer-Proxy-Sharing-Figure-1.png?uclick_id=1701a341-76aa-4885-b776-d3ad27e75534
<br>

# How does Kafka work?
## Step 1: Producer
When an event occurs, a Kafka producer formats a message (often called a record) and sends it to a Kafka topic. Each message includes a required field (value), which contains the main data, and three optional fields:

**Headers:** These are optional key-value pairs that store metadata about the message, such as HTTP headers.

**Key:** Used to specify which partition the message should go to, ensuring that all messages for a use case go to the same partition.

**Timestamp:** Marks the time the event occurred, helping Kafka to maintain chronological order within each partition.

> Placeholder Message structure in kafka

For example, if a producer is set up to send messages on driver locations, it might send a message with the driver’s ID as the key, the current GPS coordinates as the value, and optional metadata (eg: device type) in the headers.
---
**Problem #1: How do producers send massive data without overloading?**

High-volume apps (Uber driver updates) send millions of writes per second, causing:

- backpressure

- timeouts

- message drops

 **Solution** → Buffered, asynchronous writes
 Producer batches messages in memory and sends them in compressed chunks → extremely high throughput.
---
 **Problem #2: How do you avoid message loss if producer fails?**
 If a producer crashes during send → data loss.

**Solution** → `Acknowledgment levels (acks)`

acks=0 → fire and forget

acks=1 → wait for leader

acks=all → wait for ALL replicas (durability guarantee)

---

**Problem #3: Duplicate messages from retries**

Retries can cause double billing, double trip-start, etc.

**Solution** → `Idempotent Producers`

Producer gets a unique ID + sequence numbers → Kafka deduplicates automatically.
---

**Problem #4: Data from many services gets mixed up**

Trip events, driver events, and payments writing to same pipe.

**Solution** → `Topics`

Publish different data streams to different logical categories.

Examples:

driver-locations

trip-events

payments

notifications
<br>

## Step 2: Kafka EcoSystem - Topic

Problem 5: A single queue/topic cannot handle millions of messages

A normal queue becomes a bottleneck.

Kafka Internal Solution → Partitioning

A topic is split into p0, p1, p2… each handled by different brokers.

This increases throughput linearly.


<br>

## Step 3: Kafka EcoSystem - Partitioning

**Problem 6: Need ordering per trip or per driver**

Events for one driver must stay in order.
**Solution** → `Keyed Partitioning`
partition = hash(driverId) % numPartitions


All events for driverId = 123 go to same partition → guaranteed ordering.
If all messages for:
- a driver
- a trip
- a customer
go to the same partition, consumers always see events in the exact order they were produced.
---
**Problem 7: Some partitions become hot, others cold**

Driver IDs may not be evenly distributed.
**Solution** → `Sticky Partitioning + improved hashing`

Kafka balances load better with sticky partitioner.
<br>

---
## Step 4: Kafka EcoSystem - Broker

**Problem #1: How does Kafka store petabytes without slowing down?**

Traditional DB storage is too slow.

**Solution** → Log Segments (Append-Only Log)

Kafka only appends to disk → no random writes → insanely fast.
---
**Problem #2: How to handle unlimited data over time?**

Retention can cause huge logs.

**Solution** → Log Segmentation + Retention Rules

- Based on time (7 days)

- Based on size (100GB)

- Based on compaction (last update per key)

Old segments deleted safely.
---
**Problem #3: Data loss when a broker crashes**

All messages on that broker are lost.

**Solution** → Replication Factor (RF)

Each partition has:

Leader replica

Follower replicas

Followers replicate writes from the leader.

If leader dies → follower takes over.
---
**Problem #4: How to ensure consistent replicated data?**

Followers might lag behind.

Kafka Internal Solution → ISR (In-Sync Replicas)

Only replicas fully caught up remain in ISR; only these considered for acks=all.
---
**Problem #5: Handling broker failure instantly**

If leader dies, data unavailability occurs.

**Solution** → Leader Election (Zookeeper / KRaft)

Next ISR follower becomes leader automatically.
---
## Step 5: Consumers

**Problem #1: A single consumer cannot handle all events**

For massive topics (driver-locations), one consumer becomes slow.

**Solution** → Consumer Groups

Multiple consumers share the partitions.

partition-0 → consumer-A
partition-1 → consumer-B
partition-2 → consumer-C
---
**Problem #2: Overlapping consumption causes duplicates**

If two consumers read the same partition → duplicate processing.

**Solution** → `One Consumer Per Partition Rule`

Kafka ensures exclusive assignment.
---
**Problem #3: Consumer crashes → lost progress**

Stateful systems lose track of last processed message.

**Solution** → `Offset Management`

Offsets stored in the __consumer_offsets topic.

After restart → consumer resumes exactly where it stopped.
---
**Problem #4: Slow consumers create backlogs (consumer lag)**

Large queue buildup = system slow.

**Solution** → Pull Model + Flow Control

Consumers can read at their own pace; Kafka does not push.
---
**Problem #5: Bad messages crash consumers (poison messages)**

One corrupt message halts the entire pipeline.

**Solution** → `DLQ (Dead Letter Queue)`

Invalid events are moved to a separate topic for inspection.
---

## Additional Problems:
**Problem : Need exactly-once semantics in stream processing**

Ex: Fintech, billing, invoices require EXACT ONE update.

**Solution** → `Transactions + EOS`

Stream processor writes output atomically.
---
**Problem : Adding a new consumer should not break system**

Dynamic scaling must not break assignments.

**Solution** → `Rebalancing Protocol`

(KIP-429, cooperative rebalancing)

Consumers join/leave → balanced automatically.
---
**Problem : Need to sync data across regions**

India → US replication for global dashboards.

**Solution** → `Cluster Linking / MirrorMaker2`

Replicates topics across clusters safely.
---
**Problem : Region failing must not lose data**

DC outage = catastrophic.

**Solution** → `Multi-region replication + leader election`

Automatic failover.
---
**Problem : Real-time computation is hard**

ETAs, fraud detection, surge-pricing need instant processing.

**Solution** → `Kafka Streams / ksqlDB`

Supports:

- sliding windows
- aggregations
- joins
- stateful processing
- Stored in RocksDB.
---
**Problem : Schema changes break consumers**

E.g., producer adds new field → older consumers fail.

**Solution** → `Schema Registry`

Enforces:
- backward compatibility
- forward compatibility
- schema evolution rules
---
**Problem : Need strong type integrity**

Different teams send inconsistent data.

**Solution** → `Avro / Protobuf / JSON-Schema`

Strongly typed events.

**Problem : Need to replay historical events**

For ML training, fraud replay, debugging.

**Solution** → `Replay Using Offsets`

Replay old messages any time.
---
**Problem : Client libraries are complex**

Different teams, languages → onboarding pain.

**Solution** → `Proxy/Sidecar Layer`

Examples:

- Kafka REST Proxy
- Redpanda Proxy
- Custom internal “Ingest Service”

Simplifies:

- auth
- schema checking
- consistency
- rate limiting
---
**Problem : Enforcing backpressure**

Slow consumer should not affect others.

**Solution** → `Consumer lag metrics + pull model`