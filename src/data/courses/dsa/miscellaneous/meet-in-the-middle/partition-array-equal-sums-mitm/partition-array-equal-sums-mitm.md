Partition into two equal-sum subsets using MITM.

<br>

> **Key insight:** Meet in the middle variation of subset sum.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** MITM + binary search for target sum

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `MITM + binary search for target sum`

### Time Complexity: O(2^(N/2))
**Why?** Each element/state processed efficiently.

### Space Complexity: O(2^(N/2))

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(2^(N/2)) | O(2^(N/2)) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
