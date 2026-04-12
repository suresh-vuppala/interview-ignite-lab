Every element appears twice except two. Find both.

<br>

> **Key insight:** XOR all → x^y. Find a set bit (differentiator). Split into two groups by that bit. XOR each group.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** XOR all → x^y. Split by differentiating bit, XOR each group

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `XOR all → x^y. Split by differentiating bit, XOR each group`

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
