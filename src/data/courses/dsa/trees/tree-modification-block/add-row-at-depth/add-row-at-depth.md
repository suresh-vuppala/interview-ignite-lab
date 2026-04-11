Add a row of nodes with value val at given depth.

<br>

---

## Solution 1: BFS to Target Depth

BFS to depth-1, insert new nodes between current and its children.

### Time: O(n) | Space: O(n)

<br>

---

## Solution 2: DFS

Recurse to depth-1, insert new nodes.

### Time: O(n) | Space: O(h)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| BFS | O(n) | O(n) | Level-by-level to target |
| DFS | O(n) | O(h) | Recursive insertion |

<br>
<br>

---

```code```
