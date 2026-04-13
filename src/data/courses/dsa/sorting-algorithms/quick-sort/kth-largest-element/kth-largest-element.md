Find kth largest using QuickSelect.

<br>

> nums=[3,2,1,5,6,4], k=2 → 5
>
> **Key insight:** Same as kth smallest with k' = N-k+1, or partition targeting index N-k.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## All Possible Edge Cases
1. **Empty/single element input**
2. **Boundary values** (min/max of range)
3. **All elements same / sorted / reverse sorted**

<br>

---

## Solution 1: Sort and index

### Time Complexity: O(N log N)

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
