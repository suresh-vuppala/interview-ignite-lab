Find minimum number of intervals to remove to make the rest non-overlapping.

<br>

> intervals=[[1,2],[2,3],[3,4],[1,3]] → 1 (remove [1,3])
>
> **Key insight:** Same as activity selection: max non-overlapping = N - removals. Sort by end, count max non-overlapping, answer = N - count.

<br>

---

## Constraints
- Typical problem constraints apply

<br>

---

## All Possible Edge Cases
1. **Empty input:** Handle gracefully
2. **Single element:** Base case
3. **Large input:** Verify time complexity holds

<br>

---

## Solution 1: Brute Force

**Intuition:**
The most straightforward approach. Exponential search over all possible removals.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Exponential search over all possible removals.

> **Key Insight for Improvement:**
> Max non-overlapping (activity selection) gives us the answer. Removals = N - max_non_overlapping.

<br>

---

## Solution 2: Activity Selection Inverse (Optimal)

**Intuition:** Same as activity selection: max non-overlapping = N - removals. Sort by end, count max non-overlapping, answer = N - count.

**Algorithm:**
1. Sort by end time
2. Count max non-overlapping (greedy activity selection)
3. Answer = N - count

### Time Complexity: O(N log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
intervals=[[1,2],[1,3],[2,3],[3,4]] sorted by end
Non-overlapping: [1,2],[2,3],[3,4] = 3
Removals = 4 - 3 = 1 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(2^N) | Varies | Baseline |
| Activity Selection Inverse | O(N log N) | O(1) | Max non-overlapping (activity selection) gives us the answer |

**Recommended Solution:** Activity Selection Inverse — O(N log N) time, O(1) space.

**Key Insights:**
1. **Inverse of activity selection:** Minimize removals = maximize kept
2. **Sort by end time:** Same greedy reasoning
3. **LeetCode 435:** Exact formulation

<br>
<br>

---

```code```
