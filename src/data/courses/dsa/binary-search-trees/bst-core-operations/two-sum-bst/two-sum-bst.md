Check if BST contains two nodes summing to target.

<br>

---

## Solution 1: Inorder + Two Pointers — Inorder gives sorted array, apply two-sum sorted

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: BST Iterator + Two Pointers (Optimal)

Forward and backward BST iterators. Two-pointer approach without materializing array.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Inorder + Array | O(n) | O(n) | Sorted array two-sum |
| BST Iterators | O(n) | O(h) | No array, iterator-based |

<br>
<br>

---

```code```
