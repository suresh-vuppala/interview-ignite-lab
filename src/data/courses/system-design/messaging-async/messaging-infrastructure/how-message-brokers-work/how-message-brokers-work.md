
Message brokers enable asynchronous communication between systems by receiving messages from producers, storing them reliably, and delivering them to consumers.  
They act as intermediaries that decouple message creation from consumption.

<br>

---

## Broker Role

> A broker is responsible for receiving, storing, routing, and delivering messages.  
> It ensures durability, reliability, replication, and consumer coordination.

<br>

### Explanation

Brokers manage the flow of messages inside a messaging system.  
They maintain storage, track acknowledgements, manage multiple producers/consumers, and ensure that messages are delivered correctly, even during failures.

<br>

---

## Message Lifecycle

![Message Lifecycle Diagram](/Image/Fibs.png)

<br>

### Explanation

A typical message lifecycle is:

1. **Producer publishes** a message  
2. **Broker receives** it  
3. **Broker stores** it in durable logs or memory  
4. **Broker routes** it to queues/topics/partitions  
5. **Consumer pulls or receives** the message  
6. **Consumer acknowledges** after processing  

<br>

---

## Storage Internals

![Storage Diagram](/Image/Fibonaccie.png)

<br>

### Explanation

Message brokers use **append-only logs**, **segments**, and **indices** to efficiently store data.  
This design gives extremely high throughput because sequential writes are fast.

Storage may include:

- Commit logs  
- Segmented files  
- Replication logs  
- In-memory buffers  

<br>

> **Time Complexity:** O(1) amortized append  
> **Space Complexity:** O(N) where N = number of messages retained  

<br>
<br>

---

## Delivery Mechanisms


### Explanation

Delivery can be handled by:

- **Queue Model (Point-to-Point):**  
  One consumer receives each message.

- **Topic Model (Publish-Subscribe):**  
  All subscribed consumers receive the message.

- **Pull-Based Delivery:**  
  Consumers fetch messages when ready.

- **Push-Based Delivery:**  
  Broker sends messages automatically.

<br>

### Why Delivery Mechanisms Matter?

Delivery strategy impacts:

- Scalability  
- Performance  
- Ordering  
- Reliability  

<br>

**Time Complexity:** O(1) dispatch  
**Space Complexity:** O(N) queued messages  

<br>
<br>

---

## Acknowledgement Models

> ACK models ensure reliable delivery.

<br>

### Explanation

- **Auto ACK:** Immediate success  
- **Manual ACK:** Consumer confirms  
- **NACK:** Message re-delivery  

**Delivery Guarantees:**  
- At-most-once  
- At-least-once  
- Exactly-once  

<br>

**Time Complexity:** O(1)  
**Space Complexity:** O(1)  

<br>
<br>

---

## Scaling Brokers

![Scaling Diagram](/Image/Feries.png)


<br>

### Explanation

Brokers scale through:

- Partitioning  
- Clustering  
- Leader–Follower Replication  
- Consumer Groups  

<br>

**Scaling Complexity:**  
- Per broker: O(P) partitions  
- Fault tolerance: O(R) replication factor  

<br>
<br>

---
