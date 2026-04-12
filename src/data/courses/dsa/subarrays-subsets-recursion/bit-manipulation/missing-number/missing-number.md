Array of 0..N with one missing. Find it.

<br>

> **Key insight:** XOR 0..N with all array elements. Missing number remains.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** XOR(0..N) ^ XOR(array) = missing

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `XOR(0..N) ^ XOR(array) = missing`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
