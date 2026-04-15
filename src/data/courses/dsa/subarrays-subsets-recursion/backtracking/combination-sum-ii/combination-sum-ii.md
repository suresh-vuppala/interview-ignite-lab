Find unique combinations summing to target. Each number used AT MOST ONCE. No duplicate combinations.

<br>

> candidates=[10,1,2,7,6,1,5], target=8 → [[1,1,6],[1,2,5],[1,7],[2,6]]
>
> **Key insight:** Sort + backtracking. Skip duplicates at same level. Recurse with i+1 (no reuse).

<br>

---

## Constraints
- 1 ≤ N ≤ 100
- 1 ≤ candidates[i] ≤ 50
- 1 ≤ target ≤ 30

<br>

---

## All Possible Edge Cases
1. **Duplicate candidates: skip at same level
2. **Each candidate used at most once
3. **No valid combination exists**

<br>

---

## Solution 1: Generate all then filter

**Intuition:**
The most straightforward approach. Generates duplicates then filters.

**Algorithm:**
1. Enumerate all possible candidates
2. For each candidate, verify if it satisfies the condition
3. Track the best valid result
4. Return the optimal answer

### Time Complexity: O(2^N × N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Generates duplicates then filters.

> **Key Insight for Improvement:**
> Sort + skip consecutive duplicates at same level + recurse with i+1 (no reuse).

<br>

---

## Solution 2: Sort + Skip + No Reuse (Optimal)

**Intuition:** Sort + backtracking. Skip duplicates at same level. Recurse with i+1 (no reuse).

**Algorithm:**
1. Sort candidates
2. backtrack(start, remaining, current):
3. If remaining == 0: add current
4. For i = start to N-1:
   - If i > start and candidates[i]==candidates[i-1]: continue
   - If candidates[i] > remaining: break
   - Add, recurse(i+1, ...), remove

### Time Complexity: O(2^N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[1,1,2,5,6,7,10] target=8:
pick 1(idx0)→pick 1(idx1)→pick 6→[1,1,6] ✓
pick 1(idx0)→skip 1(idx1, dup at same level)→pick 2→pick 5→[1,2,5] ✓
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Generate all then filter | O(2^N × N) | Varies | Baseline |
| Sort + Skip + No Reuse | O(2^N) | O(N) | Optimal |

**Recommended Solution:** Sort + Skip + No Reuse

**Key Insights:**
1. **i+1 not i:** No element reuse
2. **i > start for skip:** Only skip at same recursion level
3. **Sort + break when too large:** Efficient pruning

<br><br>

---

```code```
