Precompute 2^k-th ancestors for O(log N) ancestor/LCA queries.

<br>

> Tree with N nodes → answer ancestor queries in O(log N)
>
> **Key insight:** up[v][k] = 2^k-th ancestor of v. up[v][k] = up[up[v][k-1]][k-1]. Precompute in O(N log N).

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Walk up one ancestor at a time

**Intuition:**
The most straightforward approach. Linear walk is slow for deep trees with many queries.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N) per query
**Why?**
Single pass through the input, doing O(1) work per element.
Total: N elements × O(1) per element = O(N).

**Detailed breakdown:**
For N=100,000: ~100,000 operations — very efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Linear walk is slow for deep trees with many queries.

> **Key Insight for Improvement:**
> Binary lifting: precompute 2^k ancestors. For query, decompose distance into powers of 2 and jump.

<br>

---

## Solution 2: Binary Lifting Table (Optimal)

**Intuition:** up[v][k] = 2^k-th ancestor of v. up[v][k] = up[up[v][k-1]][k-1]. Precompute in O(N log N).

**Algorithm:**
1. up[v][0] = parent[v]
2. up[v][k] = up[up[v][k-1]][k-1] for k=1..LOG
3. Query kth ancestor: decompose k in binary, jump for each set bit
4. LCA: lift both to same depth, then lift together until meeting

### Time Complexity: O(N log N) prep, O(log N) query
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
up[v][0]=parent, up[v][1]=grandparent, up[v][2]=4th ancestor
Query 5th ancestor: 5=101₂ → jump 2⁰=1 then 2²=4
```

### Space Complexity: O(N log N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Walk up one ancestor at a time | O(N) per query | Varies | Baseline |
| Binary Lifting Table | O(N log N) prep, O(log N) query | O(N log N) | Optimal |

**Recommended Solution:** Binary Lifting Table

**Key Insights:**
1. **2^k jumps:** Decompose any distance into O(log N) jumps
2. **LCA:** Equalize depths, then binary search for meeting point
3. **Foundation:** Heavy-light decomposition, Euler tour queries

<br><br>

---

```code```
