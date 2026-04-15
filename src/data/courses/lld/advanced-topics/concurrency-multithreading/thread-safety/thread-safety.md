# Thread Safety

> **A class is thread-safe if it behaves correctly when accessed from multiple threads, regardless of scheduling or interleaving of those threads, with no additional synchronization needed from the caller.**

<br>

---

## Why It Matters in LLD Interviews

Almost every real-world LLD problem (Parking Lot, Cache, Rate Limiter, Ticket Booking) has a concurrency dimension. Interviewers check:
- Can you identify **shared mutable state**?
- Do you know **which operations need synchronization**?
- Can you avoid **over-synchronization** (performance killer)?

<br>

---

## Three Conditions for a Race Condition

All three must be true for a bug to occur:
1. **Shared data** — multiple threads access same variable
2. **Mutable data** — at least one thread writes
3. **No synchronization** — no coordination mechanism

**Fix any one** → thread-safe.

<br>

---

## Thread Safety Strategies

### 1. Confinement — don't share
```java
// Each thread gets its own copy — no sharing, no problem
ThreadLocal<SimpleDateFormat> formatter = ThreadLocal.withInitial(
    () -> new SimpleDateFormat("yyyy-MM-dd")
);
```

### 2. Immutability — don't mutate
```java
// Immutable object — safe to share across threads
public final class Money {
    private final double amount;
    private final String currency;
    public Money(double amount, String currency) { this.amount = amount; this.currency = currency; }
    public Money add(Money other) { return new Money(this.amount + other.amount, currency); } // New object
}
```

### 3. Synchronization — coordinate access
```java
class Counter {
    private int count = 0;
    public synchronized void increment() { count++; }
    public synchronized int getCount() { return count; }
}
```

### 4. Atomic Operations — hardware-level
```java
class Counter {
    private AtomicInteger count = new AtomicInteger(0);
    public void increment() { count.incrementAndGet(); } // Lock-free!
    public int getCount() { return count.get(); }
}
```

<br>

---

## Common Thread-Safety Bugs

| Bug | Example | Fix |
|-----|---------|-----|
| **Check-then-act** | `if (!map.containsKey(k)) map.put(k, v)` | `map.putIfAbsent(k, v)` |
| **Read-modify-write** | `count++` (actually 3 ops: read, add, write) | `AtomicInteger.incrementAndGet()` |
| **Publish incomplete object** | Return `this` from constructor | Don't leak `this` during construction |

<br>

---

## Key Takeaways

1. **Identify shared mutable state** first — that's where bugs hide
2. **Prefer immutability** — no synchronization needed
3. **Use `java.util.concurrent`** — don't reinvent wheels
4. **Synchronize at the right granularity** — too broad = slow, too narrow = buggy
5. **In interviews: mention thread safety** when designing any shared resource
