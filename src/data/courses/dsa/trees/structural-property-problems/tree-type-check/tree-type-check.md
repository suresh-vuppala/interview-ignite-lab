Check if tree is Full, Complete, or Perfect binary tree.

<br>

---

## Solution 1: Recursive Checks

- **Full:** Every node has 0 or 2 children
- **Complete:** All levels full except possibly last (filled left to right)
- **Perfect:** All internal nodes have 2 children, all leaves at same level

**Complete check:** BFS — once a non-full node is seen, all remaining must be leaves.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive/BFS | O(n) | O(n) | Property-specific checks |

<br>
<br>

---

```code```
