# Memory vs CPU Trade-offs

> **"Should we cache this or compute it on the fly?"** — This question tests whether you understand the fundamental space-time trade-off.

<br>

---

## The Core Trade-off

| Approach | Memory | CPU | When |
|----------|--------|-----|------|
| **Compute on demand** | Low (no storage) | High (recompute each time) | Rarely accessed, data changes often |
| **Cache/precompute** | High (store results) | Low (lookup only) | Frequently accessed, data changes rarely |
| **Lazy computation** | Medium (cache on first access) | Medium (compute once) | Unknown access pattern |

<br>

---

## LLD Examples

### 1. Leaderboard: Precompute vs On-Demand

```java
// Option A: Compute rank on every query — O(N log N) per query, O(1) memory
int getRank(int playerId) {
    List<Integer> sorted = new ArrayList<>(scores.values());
    Collections.sort(sorted, Collections.reverseOrder());
    return sorted.indexOf(scores.get(playerId)) + 1;
}

// Option B: Maintain sorted structure — O(log N) per query, O(N) memory
TreeMap<Integer, Set<Integer>> scoreBoard; // Always sorted
int getRank(int playerId) {
    // Walk TreeMap — O(log N)
}
```

**Decision:** Read-heavy (users check rank often) → Option B (precompute). Write-heavy (scores change constantly) → Option A or hybrid.

### 2. Cache: Store vs Recompute

```java
// No cache — always fetch from DB
User getUser(int id) { return database.query("SELECT * FROM users WHERE id=?", id); }

// With cache — O(1) after first access
Map<Integer, User> cache = new HashMap<>();
User getUser(int id) {
    return cache.computeIfAbsent(id, k -> database.query("...", k));
}
// Trade-off: faster reads, but cache invalidation complexity + memory usage
```

### 3. Parking Lot: Available Count

```java
// Option A: Count on demand — scan all spots O(N)
int getAvailableCount() { return spots.stream().filter(Spot::isAvailable).count(); }

// Option B: Maintain counter — O(1) query, O(1) update on park/unpark
AtomicInteger availableCount; // Decremented on park, incremented on unpark
```

<br>

---

## How to Discuss in Interviews

> "Here I'm choosing to maintain a sorted TreeMap alongside the HashMap. It costs O(N) extra memory, but gives us O(log N) rank queries instead of O(N log N). Since users check the leaderboard frequently but scores update less often, this trade-off favors memory usage for faster reads."

<br>

---

## Key Takeaways

1. **Read-heavy → precompute/cache**, Write-heavy → compute on demand
2. **Always state the trade-off explicitly** — "I'm trading X memory for Y speedup"
3. **Quantify when possible** — "O(N) extra memory saves O(N log N) per query"
4. **Cache invalidation** is the hard part — mention it
5. **Lazy computation** is a great middle ground — compute once, cache forever
