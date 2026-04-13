Generate unique subsets when array has duplicate elements.

<br>

> nums=[1,2,2] → [[],[1],[1,2],[1,2,2],[2],[2,2]]
>
> **Key insight:** Sort. At each level, skip consecutive duplicates: if nums[i]==nums[i-1] at the same level, skip.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Generate all then deduplicate

### Time Complexity: O(N×2^N)

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
