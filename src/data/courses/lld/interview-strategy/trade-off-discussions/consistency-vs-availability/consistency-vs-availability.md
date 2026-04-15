# Consistency vs Availability (in LLD Context)

> In LLD, this trade-off manifests as: **"Should I lock this resource and block other threads, or allow slightly stale reads for better throughput?"**

<br>

---

## LLD-Level Consistency Trade-offs

### Strong Consistency (Lock Everything)
```java
// Every read sees the latest write — but slower
synchronized (account) {
    if (account.getBalance() >= amount) {
        account.withdraw(amount); // Always correct
    }
}
// Blocks all other threads during operation
```

### Eventual Consistency (Optimistic)
```java
// Fast reads, might see slightly stale data
volatile double balance; // Visibility guarantee, not atomicity
// Or: read from cache, background sync with source of truth
```

<br>

---

## Where This Shows Up in LLD

| Problem | Strong Consistency | Weaker Consistency |
|---------|-------------------|-------------------|
| **Movie Booking** | Lock seat during selection (5 min) | Show "likely available", verify at payment |
| **Parking Lot** | `synchronized` on spot assignment | Counter may be slightly off, verify at entry |
| **Leaderboard** | Lock on every score update | Batch updates every 5 seconds |
| **Cache** | Invalidate immediately on write | TTL-based expiry (stale for N seconds) |
| **Hit Counter** | Exact count with locks | Approximate count with AtomicInteger |

<br>

---

## The Spectrum

```
Strong Consistency ←────────────────────→ High Availability
   synchronized          ReadWriteLock         volatile
   Pessimistic Lock      Optimistic Lock       No Lock
   Always correct        Mostly correct        Eventually correct
   Slower                Balanced              Fastest
```

<br>

---

## How to Discuss in Interviews

### The Decision Framework

1. **What's the cost of inconsistency?**
   - Money involved (bank transfer) → Strong consistency
   - Display only (dashboard count) → Eventual is fine

2. **How often do conflicts happen?**
   - Rarely (most reads) → Optimistic locking / ReadWriteLock
   - Frequently (hot resource) → Pessimistic locking

3. **What's the read/write ratio?**
   - Read-heavy → ReadWriteLock (concurrent reads)
   - Write-heavy → Careful synchronization, batch writes

<br>

---

## Key Takeaways

1. **Not a binary choice** — it's a spectrum with many middle options
2. **Money/booking = strong consistency** (can't double-sell a seat)
3. **Display/analytics = eventual is fine** (leaderboard 5 sec stale is OK)
4. **ReadWriteLock is the sweet spot** for most LLD problems
5. **Always mention this trade-off** — it shows concurrency awareness
