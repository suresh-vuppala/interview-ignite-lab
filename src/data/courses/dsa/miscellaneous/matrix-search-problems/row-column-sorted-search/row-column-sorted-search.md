Search in matrix where each row and column is independently sorted (not globally).

<br>

> matrix=[[1,4,7],[2,5,8],[3,6,9]], target=5 → true
>
> **Key insight:** Staircase search from top-right: if target < current → go left. If target > current → go down.

<br>

---

## Constraints
- 1 ≤ M, N ≤ 300
- Each row and column independently sorted

<br>

---

## All Possible Edge Cases
1. **Target not in matrix
2. **Target at corner
3. **Multiple occurrences**

<br>

---

## Solution 1: Scan entire matrix

**Intuition:**
The most straightforward approach. Ignores sorted structure.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(M×N)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

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
