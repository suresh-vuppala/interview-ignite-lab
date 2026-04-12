Place minimum cameras on tree nodes to monitor all nodes.

<br>

> **Key insight:** Greedy postorder: each node is covered, has camera, or not covered. Parent covers uncovered child.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Postorder greedy: 0=not covered, 1=has camera, 2=covered

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Postorder greedy: 0=not covered, 1=has camera, 2=covered`

### Time Complexity: O(N)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(H)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N) | O(H) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
