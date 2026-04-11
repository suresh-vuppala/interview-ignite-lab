Trim BST to only contain values in [lo, hi].

<br>

---

## Solution 1: Recursive (Optimal)

If node.val < lo → trim(right) (left subtree all invalid).
If node.val > hi → trim(left) (right subtree all invalid).
Else → trim both children.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(n) | O(h) | BST property skips entire subtrees |

<br>
<br>

---

```code```
