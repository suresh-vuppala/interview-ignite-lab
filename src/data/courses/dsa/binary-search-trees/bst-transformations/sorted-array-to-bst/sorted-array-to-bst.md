Convert sorted array to height-balanced BST.

<br>

---

## Solution 1: Recursive Mid-Point

Pick middle element as root. Left half → left subtree. Right half → right subtree. Recurse.

### Time: O(n) | Space: O(log n) recursion

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive Mid | O(n) | O(log n) | Binary split ensures balance |

<br>
<br>

---

```code```
