Generate unique subsets when array has duplicate elements.

<br>

> nums=[1,2,2] → [[],[1],[1,2],[1,2,2],[2],[2,2]]
>
> **Key insight:** Sort. At each level, skip consecutive duplicates: if nums[i]==nums[i-1] at the same level, skip.

<br>

---

## Constraints
- 0 ≤ N ≤ 10
- -10 ≤ nums[i] ≤ 10

<br>

---

## All Possible Edge Cases
1. **No duplicates: same as power set
2. **All same: N+1 subsets
3. **Sort first to group duplicates**

<br>

---

## Solution 1: Generate all then deduplicate

**Intuition:**
The most straightforward approach. Wastes time on duplicate subsets.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N×2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Wastes time on duplicate subsets.

> **Key Insight for Improvement:**
> Sort + skip: don't pick same value twice at same recursion level.

<br>

---

## Solution 2: Sort + Skip at Same Level (Optimal)

**Intuition:** Sort. At each level, skip consecutive duplicates: if nums[i]==nums[i-1] at the same level, skip.

**Algorithm:**
1. Sort nums
2. backtrack(start, current):
3. Add current to result
4. For i = start to N-1:
   - If i > start and nums[i]==nums[i-1]: continue (skip dup at same level)
   - Add nums[i], recurse(i+1, current), remove last

### Time Complexity: O(N × unique subsets)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[1,2,2]: at level after choosing nothing: 1→..., 2→..., skip 2(dup)
After choosing 1: 2→[1,2], 2→[1,2,2], skip
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Generate all then deduplicate | O(N×2^N) | Varies | Baseline |
| Sort + Skip at Same Level | O(N × unique subsets) | O(N) | Optimal |

**Recommended Solution:** Sort + Skip at Same Level

**Key Insights:**
1. **i > start (not i > 0):** Skip only at same recursion level
2. **Sort is critical:** Makes duplicates adjacent for detection
3. **LeetCode 90:** Classic dedup backtracking

<br><br>

---

```code```
