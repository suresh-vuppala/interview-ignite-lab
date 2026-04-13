Generate all subsets of an array using bitmask enumeration.

<br>

> nums=[1,2,3] → [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
>
> **Key insight:** For N elements, iterate 0 to 2^N-1. Each bit pattern represents a subset: bit i set → include nums[i].

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

## Solution 1: Recursive backtracking

### Time Complexity: O(N×2^N)

> **Drawback:**
> Same complexity but recursion overhead.

> **Key Insight for Improvement:**
> Bitmask: each integer 0..2^N-1 maps to a unique subset. Iterate and decode bits.

<br>

---

## Solution 2: Bitmask Enumeration (Optimal)

**Intuition:** For N elements, iterate 0 to 2^N-1. Each bit pattern represents a subset: bit i set → include nums[i].

**Algorithm:**
1. For mask = 0 to 2^N - 1:
   - subset = []
   - For i = 0 to N-1: if mask & (1<<i) → add nums[i]
   - Add subset to result
2. Return result

### Time Complexity: O(N × 2^N)
**Why?**
Each element/state processed efficiently via the core technique.

**Detailed breakdown:**
Operations scale with input size as described by the complexity.

**Example walkthrough:**
```
N=3: mask=0(000)→[], mask=1(001)→[1], mask=2(010)→[2],
mask=3(011)→[1,2], mask=5(101)→[1,3], mask=7(111)→[1,2,3]
```

### Space Complexity: O(N) per subset

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive backtracking | O(N×2^N) | Varies | Baseline |
| Bitmask Enumeration | O(N × 2^N) | O(N) per subset | Optimal approach |

**Recommended Solution:** Bitmask Enumeration — O(N × 2^N) time.

**Key Insights:**
1. **2^N subsets total:** Each element included or not
2. **Bitmask = subset encoding:** Clean iterative alternative to recursion
3. **Used in:** DP with bitmask, meet-in-the-middle, combinatorial search

<br><br>

---

```code```
