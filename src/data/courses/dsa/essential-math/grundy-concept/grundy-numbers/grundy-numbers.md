Sprague-Grundy theorem for combinatorial games.

<br>

> **Key insight:** Grundy number = mex of Grundy numbers of all reachable states. XOR of Grundy numbers for combined games.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** G(state) = mex({G(next_state)}), XOR for combined games

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `G(state) = mex({G(next_state)}), XOR for combined games`

### Time Complexity: O(states × moves)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(states)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(states × moves) | O(states) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
