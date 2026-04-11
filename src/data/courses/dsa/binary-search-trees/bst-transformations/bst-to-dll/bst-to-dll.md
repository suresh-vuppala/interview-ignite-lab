Convert BST to sorted doubly linked list (in-place).

<br>

---

## Solution 1: Inorder DFS with Prev Pointer

Track prev node during inorder. Set prev.right = current, current.left = prev.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Inorder + Prev | O(n) | O(h) | Link during traversal |

<br>
<br>

---

```code```
