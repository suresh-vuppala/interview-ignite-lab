Rob maximum from binary tree — can't rob adjacent (parent-child) nodes.

<br>

> Input: [3,2,3,null,3,null,1]
> Output: 7 (rob 3 + 3 + 1 = 7)

> **Key insight:** At each node, choose: rob this node (skip children) or skip this node (take best of children).

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁴`
- `0 ≤ Node.val ≤ 10⁴`

<br>

---

## All Possible Edge Cases

1. **Single node:** Return its value
2. **All same values:** Alternating levels optimal
3. **Skewed tree:** Alternate nodes

<br>

---

## Solution 1: Naive Recursion

**Intuition:**
For each node: max(rob this + grandchildren, skip this + children).

**Problem:** Recomputes grandchildren results for every node.

### Time Complexity: O(2^n) — exponential
### Space Complexity: O(h)

> **Key Insight:** Memoize with hash map, or better — return both rob/skip from each call.

<br>

---

## Solution 2: DFS Returning (rob, skip) Pair (Optimal)

**Intuition:**
Each DFS call returns a pair: (max if we rob this node, max if we skip this node).

**Algorithm:**
```
pair<int,int> dfs(node):
    if null: return (0, 0)
    left = dfs(node.left)
    right = dfs(node.right)
    
    rob = node.val + left.skip + right.skip
    skip = max(left.rob, left.skip) + max(right.rob, right.skip)
    return (rob, skip)
```

### Time Complexity: O(n) — visit each node once
### Space Complexity: O(h) — recursion stack

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Naive Recursion | O(2^n) | O(h) | Recomputes grandchildren |
| (Rob, Skip) Pair | O(n) | O(h) | Return both options — no recomputation |

**Recommended:** DFS with (rob, skip) pair — O(n) time, O(h) space.

<br>
<br>

---

```code```
