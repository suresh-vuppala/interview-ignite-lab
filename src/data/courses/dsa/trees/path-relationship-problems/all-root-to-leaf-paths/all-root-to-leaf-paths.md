Return all root-to-leaf paths.

<br>

---

## Solution 1: DFS Backtracking

Build path string/list while traversing. At leaf, add current path to result. Backtrack.

### Time: O(n × h) — h for path copy at each leaf
### Space: O(h) recursion + O(n × h) result

<br>

---

## Solution 2: BFS with Path Tracking

Queue stores (node, path_so_far). At leaf, add to result.

### Time: O(n × h) | Space: O(n × h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS Backtrack | O(n×h) | O(h) + result | Natural recursive path building |
| BFS | O(n×h) | O(n×h) | Iterative alternative |

<br>
<br>

---

```code```
