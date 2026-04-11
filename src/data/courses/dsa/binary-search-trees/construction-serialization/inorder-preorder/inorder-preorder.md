Construct binary tree from inorder + preorder traversals.

<br>

---

## Solution 1: Recursive with HashMap

Preorder[0] = root. Find root in inorder → splits left/right subtrees. Use HashMap for O(1) index lookup.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive + Map | O(n) | O(n) | HashMap avoids O(n) search in inorder |

<br>
<br>

---

```code```
