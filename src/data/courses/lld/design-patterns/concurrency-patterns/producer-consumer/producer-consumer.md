# Producer-Consumer Pattern

> **Intent:** Decouple the production of data from its consumption using a shared buffer/queue, allowing producers and consumers to work at different rates.

<br>

---

## When to Use

- **Different production/consumption rates** — producer is faster than consumer (or vice versa)
- **Decouple components** — producer doesn't wait for consumer
- **Buffer bursts** — absorb temporary spikes in production
- **Multiple producers, multiple consumers**

<br>

---

## Implementation with BlockingQueue

```java
class ProducerConsumer {
    private final BlockingQueue<Task> queue;
    
    public ProducerConsumer(int bufferSize) {
        this.queue = new LinkedBlockingQueue<>(bufferSize);
    }
    
    class Producer implements Runnable {
        public void run() {
            while (true) {
                Task task = generateTask();
                queue.put(task); // Blocks if queue is full
                System.out.println("Produced: " + task);
            }
        }
    }
    
    class Consumer implements Runnable {
        public void run() {
            while (true) {
                Task task = queue.take(); // Blocks if queue is empty
                process(task);
                System.out.println("Consumed: " + task);
            }
        }
    }
}
```

**`BlockingQueue` handles all synchronization** — no manual locks needed!

<br>

---

## Key Takeaways

1. **Shared buffer** (queue) decouples producer from consumer
2. **BlockingQueue** in Java handles thread safety automatically
3. **Bounded buffer** prevents memory overflow — producer blocks when full
4. **Used in:** message queues, thread pools, event processing, ETL pipelines
