Serialize and deserialize a binary tree.

<br>

---

## Solution 1: Preorder with Nulls

Serialize: preorder traversal, mark nulls as "#". Deserialize: parse tokens, reconstruct preorder.

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Level-Order (BFS)

Serialize: BFS, include null markers. Deserialize: BFS reconstruction.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Preorder | O(n) | O(n) | DFS with null markers |
| Level-Order | O(n) | O(n) | BFS with null markers |

<br>
<br>

---

```code```
