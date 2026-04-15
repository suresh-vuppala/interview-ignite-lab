# Deadlock & Avoidance

> **Deadlock:** Two or more threads are blocked forever, each waiting for a lock held by the other.

<br>

---

## Four Conditions (ALL must hold)

1. **Mutual exclusion** — resource can only be held by one thread
2. **Hold and wait** — thread holds one lock while waiting for another
3. **No preemption** — locks can't be forcibly taken away
4. **Circular wait** — A waits for B, B waits for A

**Break any one condition → no deadlock.**

<br>

---

## Classic Example

```java
// Thread 1                    Thread 2
synchronized(lockA) {          synchronized(lockB) {
    synchronized(lockB) {          synchronized(lockA) {
        // work                        // work
    }                              }
}                              }
// Thread 1 holds A, waits for B
// Thread 2 holds B, waits for A → DEADLOCK!
```

<br>

---

## Prevention Strategies

### 1. Lock Ordering (Break circular wait)
```java
// Always acquire locks in SAME ORDER
void transfer(Account from, Account to, double amount) {
    Account first = from.getId() < to.getId() ? from : to;
    Account second = from.getId() < to.getId() ? to : from;
    synchronized (first) {
        synchronized (second) {
            from.withdraw(amount);
            to.deposit(amount);
        }
    }
}
```

### 2. Try-Lock with Timeout (Break hold-and-wait)
```java
if (lockA.tryLock(1, TimeUnit.SECONDS)) {
    try {
        if (lockB.tryLock(1, TimeUnit.SECONDS)) {
            try { /* work */ }
            finally { lockB.unlock(); }
        }
    } finally { lockA.unlock(); }
}
// If can't get both locks, release and retry
```

### 3. Single Lock (Coarse-grained)
```java
synchronized (globalLock) { /* do everything under one lock */ }
// Simple but limits parallelism
```

<br>

---

## Detection

- **Thread dump:** `jstack <pid>` or `Thread.getAllStackTraces()`
- **JMX:** `ThreadMXBean.findDeadlockedThreads()`
- **Log lock acquisition order** to find potential cycles

<br>

---

## Key Takeaways

1. **Lock ordering** is the most practical prevention strategy
2. **tryLock with timeout** prevents indefinite blocking
3. **Minimize lock scope** — hold locks for shortest time possible
4. **Avoid nested locks** when possible
5. **In interviews:** mention deadlock when designing any system with multiple shared resources
