Flood fill starting from (sr, sc) with new color.

<br>

---

## Solution 1: DFS — Recursive fill from start, change color
## Solution 2: BFS — Queue-based fill

**Edge case:** If new color == original color → no-op (avoid infinite loop).

### Time: O(m × n) | Space: O(m × n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS | O(m×n) | O(m×n) | Recursive fill |
| BFS | O(m×n) | O(m×n) | Iterative fill |

<br>
<br>

---

```code```
