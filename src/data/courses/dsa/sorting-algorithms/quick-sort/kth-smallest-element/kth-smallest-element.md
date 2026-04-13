Find kth smallest element using QuickSelect.

<br>

> nums=[7,10,4,3,20,15], k=3 → 7
>
> **Key insight:** QuickSelect: partition, recurse only into the half containing kth element. O(N) average.

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
> Full sort is overkill for finding one element.

> **Key Insight for Improvement:**
> QuickSelect: after partition, if pivotIdx == k-1 → found! If pivot > k-1 → search left. Else search right.

<br>

---

## Solution 2: QuickSelect (Optimal)

**Intuition:** QuickSelect: partition, recurse only into the half containing kth element. O(N) average.

**Algorithm:**
1. Partition array around pivot
2. If pivotIdx == k-1 → return arr[pivotIdx]
3. If pivotIdx > k-1 → recurse left
4. Else → recurse right

### Time Complexity: O(N) average
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
[7,10,4,3,20,15] k=3: partition→[4,3,|7|,10,20,15] pivotIdx=2=k-1 → answer=7 ✓
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
1. **Only recurse one side:** O(N+N/2+N/4+...)=O(2N)=O(N)
2. **Worst case O(N²):** Random pivot helps
3. **Same as kth-largest with adjusted k**

<br><br>

---

```code```
