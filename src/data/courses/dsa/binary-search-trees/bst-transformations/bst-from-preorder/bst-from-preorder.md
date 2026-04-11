Construct BST from preorder traversal.

<br>

---

## Solution 1: Sort → Inorder, use Preorder+Inorder — O(n log n)
## Solution 2: Recursive with Bounds (Optimal)

Use upper bound to determine when to stop. First element is root, recurse with bounds.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Sort + Build | O(n log n) | O(n) | Get inorder by sorting |
| Bounds Recursion | O(n) | O(h) | Upper bound guides construction |

<br>
<br>

---

```code```
