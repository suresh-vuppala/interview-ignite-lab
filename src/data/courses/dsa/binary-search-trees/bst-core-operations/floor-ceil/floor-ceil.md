Find floor (largest ≤ key) and ceiling (smallest ≥ key) in BST.

<br>

---

## Solution 1: BST Property Traversal

Go left if node.val > key (update ceil), go right if node.val < key (update floor).

### Time: O(h) | Space: O(1) iterative / O(h) recursive

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BST Traversal | O(h) | O(1) | BST property narrows search |

<br>
<br>

---

```code```
