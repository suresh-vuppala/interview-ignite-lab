## Count Total Nodes

**General Tree:** DFS or BFS — O(n) time, O(h) space.

**Complete Binary Tree (Optimal):**
Use property: if leftmost depth == rightmost depth → perfect → nodes = 2^h - 1.
Otherwise recurse on left and right.

### Time: O(log²n) for complete binary tree
### Space: O(log n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS/BFS | O(n) | O(h) | Visit all nodes |
| Complete BT trick | O(log²n) | O(log n) | Skip entire perfect subtrees |

<br>
<br>

---

```code```
