# Design a Hit Counter (Concurrent)

Design a thread-safe hit counter that counts events in a sliding time window.

<br>

---

## Requirements

### Main Requirements (Functional)

1. **hit(timestamp)** — record a hit at the given timestamp
2. **getHits(timestamp)** — return total hits in the past 300 seconds (5 minutes)
3. **Thread-safe** — concurrent hits from multiple threads
4. **Efficient** — O(1) hit recording, O(W) getHits where W = window size

### Extended Requirements (If Time Permits)

1. Configurable window size (not just 300 seconds)
2. Multiple counters per key (e.g., per-endpoint hit tracking)
3. Hit rate calculation (hits per second)
4. Distributed hit counter across multiple servers
5. Persistent counter (survives restarts)
6. Top-K most hit endpoints

<br>

---

## Constraints

- Window size: 300 seconds (5 minutes) default
- Timestamps: monotonically increasing (in seconds)
- Maximum hits per second: 10,000
- Memory: O(W) where W = window size in seconds
- Thread safety: support 100+ concurrent threads

<br>

---

## Identify Primary Actors

1. **Application/Service** — records hits when events occur
   - Actions: call hit(timestamp) on each event

2. **Monitoring Dashboard** — queries hit counts
   - Actions: call getHits(timestamp) to display metrics

<br>

---

## Core Entities

### 1. HitCounter
- **Attributes**: timestamps[300], hits[300] (circular arrays)
- **Methods**: hit(timestamp), getHits(timestamp)

### 2. DistributedHitCounter (Extended)
- **Attributes**: localCounters: Map<serverId, HitCounter>, aggregator
- **Methods**: hit(), getGlobalHits()

<br>

---

## Relationships (Tabular)

| Entity A | Relationship | Entity B | Type |
|----------|-------------|----------|------|
| HitCounter | uses | circular array (timestamps) | Composition (◆) |
| HitCounter | uses | AtomicIntegerArray (hits) | Composition (◆) |
| DistributedHitCounter | aggregates | HitCounter[] | Aggregation (◇) |

<br>

---

## Relationships Diagram (Textual UML)

```
  HitCounter
  -timestamps: int[300]      ← circular array
  -hits: AtomicIntegerArray[300]
  +hit(timestamp): void       ← O(1)
  +getHits(timestamp): int    ← O(300) = O(W)

  Index = timestamp % 300
  ┌────────────────────────────────────┐
  │ [0] [1] [2] ... [149] ... [299]   │ ← circular
  │  ts  ts  ts       ts       ts     │ ← if ts matches, increment
  │ cnt cnt cnt      cnt      cnt     │ ← else reset to 1
  └────────────────────────────────────┘
```

<br>

---

## Design Patterns Used

### 1. **Circular Buffer / Ring Buffer**
- **Where**: Fixed-size array indexed by `timestamp % WINDOW`
- **Why**: O(1) space, no cleanup needed — old entries are automatically overwritten
- **Benefit**: Constant memory regardless of hit volume

### 2. **Strategy Pattern** (extended)
- **Where**: Different counting strategies (exact count, approximate, HyperLogLog for unique)
- **Why**: Trade accuracy for performance in high-volume scenarios

<br>

---

## Concurrency & Thread Safety

### Thread Safety Mechanisms
- **AtomicIntegerArray** for hit counts — lock-free increment
- **synchronized block** for check-and-reset (timestamp changed → reset count)
- **Alternative**: `ReentrantLock` per bucket for finer-grained locking

### Race Conditions Handled
- **Two threads hit same timestamp**: Both increment — AtomicInteger handles atomically
- **Read during write**: getHits reads a snapshot — may see slightly stale count for current second (acceptable)
- **Timestamp rollover**: After 300 seconds, same index reused — check timestamp before counting

<br>

---

## Edge Cases & Error Handling

### Edge Cases
1. **No hits recorded** — getHits returns 0
2. **All hits in same second** — single bucket has all counts
3. **Hits spread across exactly 300 seconds** — all buckets active
4. **Timestamp in the past** — technically valid, updates old bucket (or reject if policy requires monotonic)
5. **Timestamp far in future** — invalidates many buckets at once
6. **getHits called before any hit** — return 0
7. **Very high hit rate (10K/sec)** — AtomicInteger handles this efficiently
8. **Window boundary** — hit at t=300 should not count hit at t=0

### Error Handling Strategy
- **NegativeTimestampException**: Reject timestamps < 0
- **Overflow**: Use AtomicLong instead of AtomicInteger for very high-volume counters

<br>

---

## Implementation

> See the **Java code tab** for the complete implementation including circular array approach with AtomicIntegerArray and the alternative Queue-based approach for comparison.
