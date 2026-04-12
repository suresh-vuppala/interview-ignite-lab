Game theory: Nim game. Player taking last stone wins.

<br>

> **Key insight:** If N % 4 == 0, current player loses. Otherwise wins.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** N % (maxTake+1) == 0 → lose

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `N % (maxTake+1) == 0 → lose`

### Time Complexity: O(1)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(1) | O(1) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
