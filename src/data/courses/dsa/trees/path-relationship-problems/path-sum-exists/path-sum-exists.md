Check if root-to-leaf path exists with given target sum.

<br>

> Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], target = 22
> Output: true (path: 5→4→11→2)

<br>

---

## Solution 1: DFS Recursive

**Intuition:** Subtract current value from target. At leaf, check if remaining == 0.

```
bool hasPathSum(node, target):
    if null: return false
    if leaf and target == node.val: return true
    return hasPathSum(left, target - node.val) || hasPathSum(right, target - node.val)
```

### Time: O(n) | Space: O(h)

<br>

---

## Solution 2: BFS with Running Sum

Track (node, remaining_sum) pairs in queue.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS | O(n) | O(h) | Subtract as you go |
| BFS | O(n) | O(n) | Iterative approach |

<br>
<br>

---

```code```
