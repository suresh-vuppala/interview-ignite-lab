# Read-Write Lock Pattern

> **Intent:** Allow multiple threads to read shared data simultaneously, but ensure exclusive access for write operations.

<br>

---

## Why Not Just Use synchronized?

| `synchronized` | ReadWriteLock |
|----------------|---------------|
| One thread at a time for ALL operations | Multiple readers simultaneously |
| Readers block each other (wasteful!) | Only writers need exclusive access |
| Simple but poor read performance | Optimized for read-heavy workloads |

<br>

---

## Implementation

```java
class ThreadSafeCache<K, V> {
    private final Map<K, V> cache = new HashMap<>();
    private final ReadWriteLock lock = new ReentrantReadWriteLock();
    private final Lock readLock = lock.readLock();
    private final Lock writeLock = lock.writeLock();
    
    // Multiple threads can read simultaneously
    public V get(K key) {
        readLock.lock();
        try {
            return cache.get(key);
        } finally {
            readLock.unlock();
        }
    }
    
    // Only one thread can write at a time
    public void put(K key, V value) {
        writeLock.lock();
        try {
            cache.put(key, value);
        } finally {
            writeLock.unlock();
        }
    }
    
    // Read lock for size too
    public int size() {
        readLock.lock();
        try { return cache.size(); }
        finally { readLock.unlock(); }
    }
}
```

<br>

---

## Rules

| Operation | Read Lock Held | Write Lock Held |
|-----------|:-----------:|:------------:|
| **Read** | ✅ Allowed | ❌ Blocked |
| **Write** | ❌ Blocked | ❌ Blocked |
| **Multiple Reads** | ✅ Concurrent | — |

- Multiple readers can hold read lock simultaneously
- Writer waits until ALL readers release
- New readers wait while writer holds lock

<br>

---

## Key Takeaways

1. **Read-heavy workloads benefit most** — many concurrent readers, rare writers
2. **ReentrantReadWriteLock** in Java — standard implementation
3. **Always use try-finally** — ensure lock is released even on exception
4. **Starvation risk** — continuous readers can starve writers (use fair mode)
5. **Used in:** caches, configuration stores, in-memory databases
