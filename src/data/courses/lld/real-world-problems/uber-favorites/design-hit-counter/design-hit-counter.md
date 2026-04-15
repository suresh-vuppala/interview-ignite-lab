# Design a Hit Counter (Concurrent)

Design a thread-safe hit counter that supports recording hits and querying the number of hits in the last N seconds (sliding window).

<br>

---

## Requirements

### Main Requirements
1. **hit(timestamp)** — record a hit at the given timestamp
2. **getHits(timestamp)** — return total hits in the past 300 seconds (5 min)
3. **Thread-safe** — concurrent hits from multiple threads
4. **Efficient** — O(1) hit, O(1) or O(N) getHits

<br>

---

## Approaches

### Approach 1: Queue-based — O(1) hit, O(N) getHits
Store all timestamps, remove expired ones on query.

### Approach 2: Circular array — O(1) hit, O(N) getHits (N = window size)
Fixed-size array indexed by timestamp % windowSize.

<br>

---

## Core Design

```
HitCounter
├─ times[300]: int[] — timestamp at each bucket
├─ hits[300]: int[] — hit count at each bucket
├─ hit(timestamp): void
├─ getHits(timestamp): int
```

<br>

---

## Interview Tips

- Circular array is the optimal solution — fixed memory, no cleanup needed
- Discuss: what if timestamps are not monotonically increasing?
- Thread safety: `AtomicIntegerArray` or `synchronized` blocks
- Real-world: rate limiting, analytics, monitoring
