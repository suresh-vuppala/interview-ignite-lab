Find the maximum sum among all root-to-leaf paths.

<br>

---

## Solution 1: DFS — At each node: max(leftSum, rightSum) + node.val
## Solution 2: BFS — Track sum per path, compare at leaves

### Time: O(n) | Space: O(h) or O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS | O(n) | O(h) | Return max child sum + val |
| BFS | O(n) | O(n) | Track running sums |

<br>
<br>

---

```code```
