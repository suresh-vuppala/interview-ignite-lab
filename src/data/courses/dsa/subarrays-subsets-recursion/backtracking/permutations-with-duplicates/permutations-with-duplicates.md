Generate unique permutations when array has duplicate elements.

<br>

> nums=[1,1,2] → [[1,1,2],[1,2,1],[2,1,1]]
>
> **Key insight:** Sort array. Skip duplicates at the same recursion level: if nums[i]==nums[i-1] and i-1 was not used at this level, skip.

<br>

---

## Constraints
- 1 ≤ N ≤ 8
- Elements may repeat

<br>

---

## Solution 1: Generate all then deduplicate

**Intuition:**
The most straightforward approach. Generates duplicates then filters — wasteful.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(N×N!)
**Why?**
Generating all permutations requires N! arrangements.
Each permutation requires O(N) work to construct and verify.

**Detailed breakdown:**
For N=10: ~3.6 million. For N=12: ~479 million. For N=15: ~1.3 trillion — infeasible.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

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
