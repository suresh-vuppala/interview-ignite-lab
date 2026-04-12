Generate all subsets using bitmask enumeration.

<br>

> **Key insight:** For N elements, iterate 0 to 2^N-1. Each bit pattern represents a subset.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Iterate 0..2^N-1, bit i set → include element i

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Iterate 0..2^N-1, bit i set → include element i`

### Time Complexity: O(N × 2^N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N × 2^N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
