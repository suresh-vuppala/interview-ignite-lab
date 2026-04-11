Capture 'O' regions that are completely surrounded by 'X'. Border-connected 'O's survive.

<br>

---

## Solution 1: DFS/BFS from Borders (Optimal)

**Intuition:** Mark all 'O's connected to borders as safe. Everything else gets captured.

**Algorithm:**
1. DFS/BFS from all border 'O' cells → mark as 'S' (safe)
2. Scan grid: remaining 'O' → 'X' (captured), 'S' → 'O' (restore)

### Time: O(m × n) | Space: O(m × n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Border DFS/BFS | O(m×n) | O(m×n) | Mark safe from borders, flip rest |

<br>
<br>

---

```code```
