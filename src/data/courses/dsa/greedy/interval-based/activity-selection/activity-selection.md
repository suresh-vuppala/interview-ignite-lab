Select maximum number of non-overlapping activities given start and end times.

<br>

> activities=[(1,4),(3,5),(0,6),(5,7),(8,9),(5,9)] → 3 activities
>
> **Key insight:** Sort by end time ascending. Greedily select the earliest-ending activity that doesn't conflict with the last selected.

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
The most straightforward approach. Exponential — checking all subsets is infeasible for large N.

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
> Exponential — checking all subsets is infeasible for large N.

> **Key Insight for Improvement:**
> Greedy: earliest end time first leaves maximum room for future activities. Provably optimal.

<br>

---

## Solution 2: Sort by End Time + Greedy Select (Optimal)

**Intuition:** Sort by end time ascending. Greedily select the earliest-ending activity that doesn't conflict with the last selected.

**Algorithm:**
1. Sort activities by end time
2. Select first activity
3. For each remaining: if start ≥ last selected's end → select it
4. Count selected

### Time Complexity: O(N log N)
**Why?**
Each element processed at most once through the core data structure/algorithm.

**Detailed breakdown:**
For typical input sizes, operations stay well within time limits.

**Example walkthrough:**
```
Activities sorted by end: (1,4),(3,5),(0,6),(5,7),(5,9),(8,9)
Select (1,4). Skip (3,5) start<4. Skip (0,6). Select (5,7) start≥4. Select (8,9) start≥7.
Total: 3 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(2^N) | Varies | Baseline |
| Sort by End Time + Greedy Select | O(N log N) | O(1) | Greedy: earliest end time first leaves maximum room for futu |

**Recommended Solution:** Sort by End Time + Greedy Select — O(N log N) time, O(1) space.

**Key Insights:**
1. **Earliest end time:** Leaves maximum remaining time for future activities
2. **Greedy proof:** Any other choice can only reduce or maintain the count
3. **Foundation for:** Interval scheduling, non-overlapping intervals

<br>
<br>

---

```code```
