Map digits to letters, generate all combinations.

<br>

> **Key insight:** Backtracking: for each digit, try all mapped letters.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Backtrack: for each digit append each mapped letter

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Backtrack: for each digit append each mapped letter`

### Time Complexity: O(4^N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(4^N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
