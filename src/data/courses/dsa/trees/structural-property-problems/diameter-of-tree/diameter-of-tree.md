Find the diameter (longest path between any two nodes, measured in edges).

<br>

> Input: [1,2,3,4,5] → Output: 3 (path: 4→2→1→3)

<br>

---

## Constraints

- `1 ≤ n ≤ 10⁴`

<br>

---

## Solution 1: Brute Force — DFS from Every Node

For each node, find farthest node via DFS. Take max distance.

### Time: O(n²) | Space: O(h)

<br>

---

## Solution 2: Single DFS (Optimal)

**Intuition:** At each node, the longest path THROUGH that node = leftHeight + rightHeight. Track global max while computing heights.

**Algorithm:**
```
int diameter = 0
int height(node):
    if null: return 0
    left = height(node.left)
    right = height(node.right)
    diameter = max(diameter, left + right)  // Path through this node
    return 1 + max(left, right)
```

### Time: O(n) — single DFS
### Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS from every node | O(n²) | O(h) | Check all starting points |
| Single DFS | O(n) | O(h) | Track diameter while computing height |

<br>
<br>

---

```code```
