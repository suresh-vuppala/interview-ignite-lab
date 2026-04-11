Find the Lowest Common Ancestor of two nodes in a binary tree.

<br>

> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
> Output: 3

<br>

---

## Constraints

- `2 ≤ n ≤ 10⁵`
- `All values unique`
- `Both p and q exist in the tree`

<br>

---

## Solution 1: Store Paths + Compare

**Intuition:** Find path from root to p and root to q. Last common node in both paths is LCA.

### Time: O(n) | Space: O(n) for paths

<br>

---

## Solution 2: DFS Recursive (Optimal)

**Intuition:** If current node is p or q, return it. Recurse left and right. If both return non-null, current node is LCA. If only one returns non-null, propagate it up.

**Algorithm:**
```
TreeNode lca(node, p, q):
    if node is null or node == p or node == q: return node
    left = lca(node.left, p, q)
    right = lca(node.right, p, q)
    if left and right: return node  // p and q in different subtrees
    return left ?? right  // Both in same subtree
```

### Time: O(n) — visit each node once
### Space: O(h) — recursion stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Store Paths | O(n) | O(n) | Compare two root-to-node paths |
| DFS Recursive | O(n) | O(h) | Propagate results up — no path storage |

<br>
<br>

---

```code```
