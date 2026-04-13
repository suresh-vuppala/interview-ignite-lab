Generate unique permutations when array has duplicate elements.

<br>

> nums=[1,1,2] → [[1,1,2],[1,2,1],[2,1,1]]
>
> **Key insight:** Sort array. Skip duplicates at the same recursion level: if nums[i]==nums[i-1] and i-1 was not used at this level, skip.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Generate all then deduplicate

### Time Complexity: O(N×N!)

> **Drawback:**
> Generates duplicates then filters — wasteful.

> **Key Insight for Improvement:**
> Sort + skip: at each level, don't pick the same value twice. Sort ensures duplicates are adjacent.

<br>

---

## Solution 2: Sort + Skip Duplicates (Optimal)

**Intuition:** Sort array. Skip duplicates at the same recursion level: if nums[i]==nums[i-1] and i-1 was not used at this level, skip.

**Algorithm:**
1. Sort nums
2. backtrack(used[], current):
3. If current.size == N: add to result
4. For i = 0 to N-1:
   - If used[i]: continue
   - If i>0 and nums[i]==nums[i-1] and !used[i-1]: continue (skip dup)
   - Mark used, add to current, recurse, backtrack

### Time Complexity: O(N × unique perms)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[1,1,2] sorted: pick 1(idx0)→pick 1(idx1)→pick 2→[1,1,2]
Backtrack: skip 1(idx1) if idx0 not used→avoids duplicate
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Generate all then deduplicate | O(N×N!) | Varies | Baseline |
| Sort + Skip Duplicates | O(N × unique perms) | O(N) | Optimal |

**Recommended Solution:** Sort + Skip Duplicates

**Key Insights:**
1. **Sort ensures duplicates adjacent:** Can detect and skip
2. **!used[i-1] check:** Ensures first occurrence is used before second
3. **Significant pruning:** Avoids generating identical permutations

<br><br>

---

```code```
