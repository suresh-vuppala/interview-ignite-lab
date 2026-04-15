# Concurrent Collections

Java's `java.util.concurrent` package provides thread-safe collections optimized for concurrent access.

<br>

---

## ConcurrentHashMap

```java
ConcurrentHashMap<String, Integer> map = new ConcurrentHashMap<>();

// Atomic operations — no external synchronization needed
map.put("key", 1);
map.putIfAbsent("key", 2);          // Only if absent
map.computeIfAbsent("key", k -> expensiveCompute(k)); // Lazy compute
map.merge("key", 1, Integer::sum);  // Atomic merge

// ❌ NOT atomic — still needs synchronization
if (!map.containsKey("key")) {      // Check
    map.put("key", value);           // Act — another thread may have put between!
}
// ✅ Use atomic method instead
map.putIfAbsent("key", value);
```

### HashMap vs ConcurrentHashMap vs Hashtable

| | HashMap | Hashtable | ConcurrentHashMap |
|--|---------|-----------|-------------------|
| **Thread-safe** | ❌ No | ✅ Yes | ✅ Yes |
| **Lock granularity** | N/A | Whole map | Bucket-level (segments) |
| **Null keys/values** | Allowed | ❌ No | ❌ No |
| **Performance** | Best (single-thread) | Worst (global lock) | Good (concurrent) |

<br>

---

## BlockingQueue

```java
BlockingQueue<Task> queue = new LinkedBlockingQueue<>(100); // Bounded

// Producer
queue.put(task);    // BLOCKS if queue is full
queue.offer(task, 5, TimeUnit.SECONDS); // Waits up to 5 sec

// Consumer
Task t = queue.take();    // BLOCKS if queue is empty
Task t = queue.poll(5, TimeUnit.SECONDS); // Waits up to 5 sec
```

### BlockingQueue Implementations

| Type | Ordering | Bounded |
|------|----------|---------|
| `LinkedBlockingQueue` | FIFO | Optional |
| `ArrayBlockingQueue` | FIFO | Always |
| `PriorityBlockingQueue` | Priority | Unbounded |
| `SynchronousQueue` | Direct handoff | Zero capacity |

<br>

---

## CopyOnWriteArrayList

```java
// Best for: rarely modified, frequently read lists (e.g., listener lists)
CopyOnWriteArrayList<EventListener> listeners = new CopyOnWriteArrayList<>();
listeners.add(listener);          // Creates new copy of entire array!
for (EventListener l : listeners) // Safe iteration — no ConcurrentModificationException
    l.onEvent(event);
```

<br>

---

## Key Takeaways

1. **ConcurrentHashMap** — default choice for thread-safe maps
2. **BlockingQueue** — core of Producer-Consumer pattern
3. **CopyOnWriteArrayList** — read-heavy, write-rare scenarios (observer lists)
4. **Use atomic methods** (`putIfAbsent`, `computeIfAbsent`) instead of check-then-act
5. **Never use `Hashtable` or `Collections.synchronizedMap`** — use `ConcurrentHashMap`
