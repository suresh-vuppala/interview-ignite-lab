C++ unordered_map/unordered_set internals: hash function, buckets, load factor.

<br>

> How std::unordered_map works internally
>
> **Key insight:** Default hash function, bucket array, chaining for collisions, rehashing when load factor exceeds threshold.

<br>

---

## Constraints
- std::unordered_map / unordered_set internals

<br>

---

## All Possible Edge Cases
1. **Hash collision causing O(N) lookup
2. **Rehashing on load factor exceeded
3. **Custom hash for composite keys**

<br>

---

## Solution 1: N/A — implementation knowledge

**Intuition:**
The most straightforward approach. Hash collisions degrade to O(N) in worst case.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(1) average
**Why?**
The approach processes each state/element with the work described by the complexity.
Total operations scale accordingly with input size.

**Detailed breakdown:**
Verify against constraint limits to ensure it passes within time.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Hash collisions degrade to O(N) in worst case.

> **Key Insight for Improvement:**
> Custom hash functions and reserve() can improve performance. Robin Hood hashing for cache efficiency.

<br>

---

## Solution 2: Hash Table Internals (Optimal)

**Intuition:** Default hash function, bucket array, chaining for collisions, rehashing when load factor exceeds threshold.

**Algorithm:**
Buckets: array of linked lists (chaining)
Load factor: elements/buckets, rehash when > max_load_factor (default 1.0)
Hash: std::hash<T> for built-in types, custom for pairs/structs

### Time Complexity: O(1) average, O(N) worst
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
unordered_map<int,int> m; m[5]=10; // hash(5) → bucket index → store (5,10)
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — implementation knowledge | O(1) average | Varies | Baseline |
| Hash Table Internals | O(1) average, O(N) worst | O(N) | Optimal |

**Recommended Solution:** Hash Table Internals

**Key Insights:**
1. **Custom hash for pairs:** Default doesn't work — provide hash function
2. **reserve(N):** Pre-allocate to avoid rehashing
3. **Worst case O(N):** Adversarial inputs → use hash randomization

<br><br>

---

```code```
