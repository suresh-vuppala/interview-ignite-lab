Find kth largest using QuickSelect.

<br>

> nums=[3,2,1,5,6,4], k=2 → 5
>
> **Key insight:** Same as kth smallest with k' = N-k+1, or partition targeting index N-k.

<br>

---

## Constraints
- 1 ≤ K ≤ N ≤ 10⁵

<br>

---

## All Possible Edge Cases
1. **K = 1:** maximum
2. **K = N:** minimum
3. **All equal**

<br>

---

## Solution 1: Sort and index

**Intuition:**
The most straightforward approach. Same overkill.

**Algorithm:**
1. Sort the input array
2. Iterate through the sorted array
3. Check the required condition at each step

### Time Complexity: O(N log N)
**Why?**
Sorting or divide-and-conquer requires O(N log N).
Each of log N levels processes N elements.

**Detailed breakdown:**
For N=100,000: ~1.7 million operations — efficient.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Same overkill.

> **Key Insight for Improvement:**
> QuickSelect targeting index N-k.

<br>

---

## Solution 2: QuickSelect (Optimal)

**Intuition:** Same as kth smallest with k' = N-k+1, or partition targeting index N-k.

**Algorithm:**
Same as kth-smallest with target index = N-k

### Time Complexity: O(N) average
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[3,2,1,5,6,4] k=2→target idx=4: partition→[3,2,1,4,|5|,6] idx=4→answer=5 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort and index | O(N log N) | Varies | Baseline |
| QuickSelect | O(N) average | O(1) | Optimal approach |

**Recommended Solution:** QuickSelect — O(N) average time.

**Key Insights:**
1. **kth largest = (N-k+1)th smallest**
2. **Same QuickSelect algorithm**
3. **Min-heap of size K:** Alternative O(N log K) guaranteed

<br><br>

---

```code```
