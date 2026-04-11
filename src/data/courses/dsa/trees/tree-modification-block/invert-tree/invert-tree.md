Invert a binary tree (swap all left and right children).

<br>

> Input: [4,2,7,1,3,6,9]
> Output: [4,7,2,9,6,3,1]

<br>

---

## Solution 1: Recursive (DFS)

**Intuition:** Swap left and right children, then recurse.

```
TreeNode invert(node):
    if null: return null
    swap(node.left, node.right)
    invert(node.left)
    invert(node.right)
    return node
```

### Time: O(n) | Space: O(h)

<br>

---

## Solution 2: Iterative (BFS)

Use queue. For each node, swap its children, enqueue non-null children.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive DFS | O(n) | O(h) | Swap + recurse |
| Iterative BFS | O(n) | O(n) | Queue-based swap |

<br>
<br>

---

```code```
