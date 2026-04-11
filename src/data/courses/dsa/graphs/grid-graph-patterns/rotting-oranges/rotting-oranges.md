Find minimum time for all oranges to rot (multi-source BFS).

<br>

> Input: [[2,1,1],[1,1,0],[0,1,1]]
> Output: 4

<br>

---

## Solution 1: Multi-Source BFS (Optimal)

**Intuition:** Start BFS from ALL rotten oranges simultaneously. Each BFS level = 1 minute.

**Algorithm:**
1. Enqueue all rotten oranges, count fresh
2. BFS level by level
3. Each level rots adjacent fresh oranges
4. If fresh count reaches 0 → return minutes
5. If BFS ends with fresh remaining → return -1

### Time: O(m × n) | Space: O(m × n)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Multi-Source BFS | O(m×n) | O(m×n) | All rotten start simultaneously |

<br>
<br>

---

```code```
