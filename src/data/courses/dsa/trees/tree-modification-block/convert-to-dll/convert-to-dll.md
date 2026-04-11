Convert binary tree to doubly linked list (inorder).

<br>

---

## Solution 1: Inorder → Array → Link

Collect inorder traversal, create DLL from array.

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: Inorder DFS with Prev Pointer (Optimal)

Track `prev` pointer. During inorder: prev.right = current, current.left = prev, update prev.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Array | O(n) | O(n) | Intermediate storage |
| DFS + Prev | O(n) | O(h) | Link during traversal |

<br>
<br>

---

```code```
