Prune binary tree: remove subtrees not containing 1.

<br>

---

## Solution 1: Postorder DFS

If node is leaf and value is 0 → return null. Process children first (postorder), then check.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Postorder | O(n) | O(h) | Bottom-up pruning |

<br>
<br>

---

```code```
