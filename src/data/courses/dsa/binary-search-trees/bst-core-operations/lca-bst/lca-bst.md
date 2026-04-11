Find LCA in BST — simpler than general BT since we have ordering.

<br>

---

## Solution 1: General BT LCA — O(n) DFS

<br>

---

## Solution 2: BST Property (Optimal)

If both p,q < node → go left. If both > node → go right. Otherwise current node is LCA.

### Time: O(h) | Space: O(1) iterative

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| General DFS | O(n) | O(h) | Visit all nodes |
| BST Property | O(h) | O(1) | Order guides direction |

<br>
<br>

---

```code```
