# Synchronization

Synchronization ensures that only one thread at a time executes a critical section of code that accesses shared data.

<br>

---

## Java Synchronization Tools

### 1. `synchronized` keyword

```java
// Method-level
public synchronized void transfer(Account to, double amount) { ... }

// Block-level (finer granularity)
public void transfer(Account to, double amount) {
    synchronized (this) {
        this.balance -= amount;
    }
    synchronized (to) {
        to.balance += amount;
    }
}
```

### 2. `ReentrantLock` (more features)

```java
Lock lock = new ReentrantLock();
lock.lock();
try {
    // Critical section
} finally {
    lock.unlock(); // MUST unlock in finally
}

// Timed locking — avoids infinite waiting
if (lock.tryLock(5, TimeUnit.SECONDS)) {
    try { /* work */ }
    finally { lock.unlock(); }
} else {
    // Couldn't acquire lock in 5 seconds — handle gracefully
}
```

### 3. `Atomic*` classes (lock-free)

```java
AtomicInteger counter = new AtomicInteger(0);
counter.incrementAndGet();    // Atomic increment
counter.compareAndSet(5, 10); // CAS: if value is 5, set to 10
```

### 4. `volatile` keyword

```java
private volatile boolean running = true; // Visibility guarantee only
// All threads see the latest value — but NOT atomic for compound operations
```

<br>

---

## synchronized vs Lock vs Atomic

| Feature | synchronized | ReentrantLock | Atomic |
|---------|-------------|---------------|--------|
| **Ease of use** | Simplest | More complex | Simple for counters |
| **Fairness** | No | Optional (`new ReentrantLock(true)`) | N/A |
| **Try-lock** | No | `tryLock(timeout)` | N/A |
| **Read-write** | No | `ReadWriteLock` | N/A |
| **Condition** | `wait()/notify()` | `Condition` objects | N/A |
| **Performance** | Good | Good | Best (lock-free) |
| **Scope** | Method/block | Flexible | Single variable |

<br>

---

## Key Takeaways

1. **`synchronized`** for simple cases — auto-releases on exception
2. **`ReentrantLock`** when you need tryLock, fairness, or read-write locks
3. **`Atomic*`** for counters and flags — best performance (lock-free)
4. **`volatile`** for visibility only — NOT for compound operations like `count++`
5. **Always use try-finally** with explicit locks to prevent deadlocks
