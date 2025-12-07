## Producers
> Producers are applications or services that create and send messages to a messaging system such as Kafka, RabbitMQ, or Pulsar.

<br>

### Key Points
> - Responsible for generating data  
> - Publish messages to queues or topics  
> - Support batching, retries, and acknowledgements  
> - Decide routing logic (topic, partition, key)

<br>
<br>

---

## Consumers
> Consumers are applications that read and process messages from queues or topics.

<br>

### Key Points
> - Pull messages from the messaging system  
> - Can be part of a consumer group for load balancing  
> - Maintain offsets to track processed messages  
> - Provide manual or auto acknowledgement modes

<br>
<br>

---

## Queues
> A Queue follows a point-to-point messaging model where each message is delivered to exactly one consumer.

<br>

### Key Points
> - Ensures load balanced consumption  
> - Suitable for background jobs and task distribution  
> - Messages are removed once consumed  
> - Guarantees at-least-once or exactly-once delivery depending on configuration

<br>
<br>

---

## Topics
> A Topic follows a publish-subscribe model where each message can be delivered to multiple consumers.

<br>

### Key Points
> - Producers publish events to topics  
> - Consumers subscribe to topics and receive a copy of each message  
> - Enables event-driven architecture  
> - Used heavily in streaming platforms like Kafka

<br>
<br>

---

## Brokers
> A Broker is a server that stores, routes, and delivers messages between producers and consumers.

<br>

### Key Points
> - Manages message persistence and replication  
> - Handles client connections from producers and consumers  
> - Multiple brokers form a cluster for scalability  
> - Provides fault tolerance by distributing partitions across nodes

<br>
<br>

---

## Partitions
> Partitions divide a topic into multiple ordered logs, enabling parallelism and scalability.

<br>

### Key Points
> - Each partition is an append-only log  
> - Producers can write based on key routing  
> - Consumers read sequentially per partition  
> - Allow horizontal scaling across multiple brokers

<br>
<br>

---

## Offsets / Acknowledgements
> Offsets track the position of a consumer within a partition, while acknowledgements confirm message processing.

<br>

### Key Points
> - Offset = index of message inside a partition  
> - Consumers use offsets to resume after restarts  
> - Acknowledgements ensure reliable delivery  
> - Support auto-commit, manual commit, or transactional commit modes

<br>
<br>

---

## Message Formats
> Message formats define how data is structured when sent between producers and consumers.

<br>

### Key Points
> - Common formats: JSON, Avro, Protobuf, XML  
> - Include metadata like headers, keys, timestamps  
> - Binary formats (Avro/Protobuf) provide schema enforcement  
> - Enable serialization/deserialization between services

<br>
<br>

---
