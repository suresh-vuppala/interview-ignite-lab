Find the size of the largest BST subtree in a binary tree.

<br>

> **Key insight:** Postorder: each node returns (size, min, max, isBST). Merge bottom-up.

<br>

---

## Constraints
- Standard constraints

<br>

---

## Solution 1: Brute Force

> **Drawback:** Suboptimal time complexity.

> **Key Insight for Improvement:** Postorder returning (isBST, size, min, max)

<br>

---

## Solution 2: Optimal

**Recurrence/Approach:** `Postorder returning (isBST, size, min, max)`

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
