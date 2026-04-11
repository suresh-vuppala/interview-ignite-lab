Group nodes by diagonal (going right is same diagonal, going left is next diagonal).

<br>

---

## Solution 1: DFS with Diagonal Index — Track diagonal level, group by it
## Solution 2: BFS with Queue — Process diagonals level by level

### Time: O(n) | Space: O(n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS + Map | O(n) | O(n) | Map diagonal → nodes |
| BFS | O(n) | O(n) | Level-by-level diagonal processing |

<br>
<br>

---

```code```
