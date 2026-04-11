Count nodes where no ancestor has a greater value (node is "good").

<br>

> Input: [3,1,4,3,null,1,5]
> Output: 4 (nodes 3, 3, 4, 5)

<br>

---

## Solution 1: DFS with Max Tracking (Optimal)

**Intuition:** Track maximum value from root to current node. If node.val >= maxSoFar, it's a good node.

**Algorithm:**
```
int dfs(node, maxSoFar):
    if null: return 0
    count = (node.val >= maxSoFar) ? 1 : 0
    newMax = max(maxSoFar, node.val)
    return count + dfs(left, newMax) + dfs(right, newMax)
```

### Time: O(n) | Space: O(h)

<br>

---

## Solution 2: BFS with Max Tracking

Queue stores (node, maxSoFar). Same logic iteratively.

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Max | O(n) | O(h) | Pass max down recursively |
| BFS + Max | O(n) | O(n) | Queue with max tracking |

<br>
<br>

---

```code```
