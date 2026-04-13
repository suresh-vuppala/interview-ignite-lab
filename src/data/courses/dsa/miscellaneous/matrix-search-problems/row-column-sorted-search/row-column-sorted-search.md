Search in matrix where each row and column is independently sorted (not globally).

<br>

> matrix=[[1,4,7],[2,5,8],[3,6,9]], target=5 → true
>
> **Key insight:** Staircase search from top-right: if target < current → go left. If target > current → go down.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Scan entire matrix

### Time Complexity: O(M×N)

> **Drawback:**
> Ignores sorted structure.

> **Key Insight for Improvement:**
> Top-right corner: move left (smaller) or down (larger). Eliminates one row or column per step.

<br>

---

## Solution 2: Staircase Search (Optimal)

**Intuition:** Staircase search from top-right: if target < current → go left. If target > current → go down.

**Algorithm:**
1. Start at (0, N-1) — top-right corner
2. If matrix[r][c] == target → found
3. If matrix[r][c] > target → c-- (go left)
4. If matrix[r][c] < target → r++ (go down)

### Time Complexity: O(M+N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
[[1,4,7],[2,5,8],[3,6,9]] target=5:
Start (0,2)=7>5→left. (0,1)=4<5→down. (1,1)=5 ✓
```

### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Scan entire matrix | O(M×N) | Varies | Baseline |
| Staircase Search | O(M+N) | O(1) | Optimal |

**Recommended Solution:** Staircase Search

**Key Insights:**
1. **Top-right or bottom-left:** Both work as starting points
2. **Eliminates row or column:** Each step removes one possibility
3. **O(M+N):** At most M+N steps

<br><br>

---

```code```
