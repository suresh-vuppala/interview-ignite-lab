In a grid, fresh oranges (1) rot when adjacent to rotten oranges (2) each minute. Return the minimum minutes until no fresh oranges remain, or -1 if impossible.

<br>

> Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
> Output: 4
> **Key insight:** Multi-source BFS. All initial rotten oranges are sources. BFS level = one minute. Count levels until no fresh remain.

<br>

---

## Constraints
- `1 ≤ m, n ≤ 10`

<br>

---

## Solution: Multi-Source BFS (Optimal)

**Algorithm:**
1. Enqueue ALL rotten oranges (multi-source). Count fresh oranges.
2. BFS: each level = one minute. Rot adjacent fresh oranges, decrement fresh count.
3. After BFS: if fresh > 0 → return -1. Else return minutes.

### Time Complexity: O(M × N)
**Why?** Each cell processed at most once.

**Detailed breakdown:** 10×10 = 100 cells max

### Space Complexity: O(M × N) for queue

> **Drawback:** None — BFS naturally gives minimum time (shortest path from any rotten source).

> **Key Insight for Improvement:** Multi-source BFS: enqueue ALL sources at once. This finds the minimum time from the NEAREST rotten orange to each fresh one, simultaneously.

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Multi-Source BFS | O(M×N) | O(M×N) | All rotten as sources, level = minute |

**Key Insights:**
1. **Multi-source BFS:** All rotten oranges start simultaneously
2. **Level = time step:** Each BFS level represents one minute
3. **Check remaining fresh:** After BFS, if any fresh left → -1
4. **FAANG favorite:** Tests multi-source BFS understanding

<br><br>

---

```code```
