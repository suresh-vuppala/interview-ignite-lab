Find all nodes at distance K from a target node in a binary tree.

<br>

> **Key insight:** Convert tree to graph (add parent pointers). BFS from target for K levels.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Parent map + BFS from target K levels

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Parent map + BFS from target K levels`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(N) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
