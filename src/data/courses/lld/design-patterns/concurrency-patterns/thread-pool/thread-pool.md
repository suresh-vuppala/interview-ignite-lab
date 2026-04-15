# Thread Pool Pattern

> **Intent:** Maintain a pool of pre-created threads that can be reused to execute tasks, avoiding the overhead of creating and destroying threads for each task.

<br>

---

## Why Thread Pools

| Without Pool | With Pool |
|-------------|-----------|
| Create thread per request | Reuse existing threads |
| OS thread creation is expensive (~1ms) | Threads already created |
| Unbounded → can crash with too many threads | Bounded → predictable resource usage |
| No control over concurrency | Fine-grained control |

<br>

---

## Java ExecutorService

```java
// Fixed thread pool — most common
ExecutorService pool = Executors.newFixedThreadPool(10);

// Submit tasks
pool.submit(() -> processOrder(order1));
pool.submit(() -> processOrder(order2));

// Submit with result
Future<Double> future = pool.submit(() -> calculateTotal(order));
double total = future.get(); // Blocks until result ready

// Shutdown gracefully
pool.shutdown();
pool.awaitTermination(30, TimeUnit.SECONDS);
```

<br>

---

## Custom Thread Pool

```java
ThreadPoolExecutor executor = new ThreadPoolExecutor(
    5,                          // Core pool size
    20,                         // Maximum pool size
    60, TimeUnit.SECONDS,       // Keep-alive time for idle threads
    new LinkedBlockingQueue<>(100), // Task queue (bounded!)
    new ThreadPoolExecutor.CallerRunsPolicy() // Rejection policy
);
```

### Rejection Policies (when queue is full + all threads busy):
- **AbortPolicy** — throws RejectedExecutionException (default)
- **CallerRunsPolicy** — caller's thread runs the task (backpressure)
- **DiscardPolicy** — silently drops the task
- **DiscardOldestPolicy** — drops oldest queued task

<br>

---

## Key Takeaways

1. **Reuse threads** — avoid creation/destruction overhead
2. **Bounded concurrency** — control max simultaneous tasks
3. **`Executors.newFixedThreadPool(n)`** — most common in interviews
4. **Always shutdown** — `pool.shutdown()` to prevent resource leaks
5. **Choose rejection policy** wisely — CallerRunsPolicy gives natural backpressure
