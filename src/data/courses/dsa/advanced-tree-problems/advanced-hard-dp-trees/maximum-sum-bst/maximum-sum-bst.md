Find maximum sum of any BST subtree.

<br>

> **Key insight:** Same as largest BST but track sum instead of size.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Postorder: track sum + BST validity

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Postorder: track sum + BST validity`

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
