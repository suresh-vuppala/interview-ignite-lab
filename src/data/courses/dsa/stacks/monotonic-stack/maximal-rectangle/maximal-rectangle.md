Given a binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

<br>

> Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
> Output: 6

> Explanation: The maximal rectangle spans rows 1-2, columns 2-4 (3×2=6).
> 
> **Key insight:** Build histogram heights per row. For each row, apply Largest Rectangle in Histogram algorithm. max across all rows = answer.

<br>

---

## Constraints
- `1 ≤ rows, cols ≤ 200`

<br>

---

## Solution 1: Brute Force — Check All Rectangles

### Time Complexity: O(R² × C²)

> **Drawback:** Checking all possible rectangles. We can reduce to O(R×C) by building on Largest Rectangle in Histogram.

> **Key Insight for Improvement:** For each row, build a "histogram" of heights — height[j] = consecutive 1s above (including current row). Apply the O(C) Largest Rectangle in Histogram per row. Total: O(R×C).

<br>

---

## Solution 2: Row-by-Row Histogram + Monotonic Stack (Optimal)

**Algorithm:**
1. Build heights array: for each row, if matrix[i][j]='1' → heights[j]++, else heights[j]=0
2. For each row, apply Largest Rectangle in Histogram on heights
3. Track max area across all rows

### Time Complexity: O(R × C)
**Why?** R rows × O(C) per histogram computation.

**Detailed breakdown:** 200 × 200 = 40,000 operations

**Example walkthrough:**
```
Row 0 heights: [1,0,1,0,0] → max rect = 1
Row 1 heights: [2,0,2,1,1] → max rect = 3
Row 2 heights: [3,1,3,2,2] → max rect = 6 ★
Row 3 heights: [4,0,0,3,0] → max rect = 4

Answer: 6 ✓
```

### Space Complexity: O(C)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(R²×C²) | O(1) | Check all rectangles |
| Histogram + Stack | O(R×C) | O(C) | Build on Largest Rect in Histogram |

**Key Insights:**
1. **2D → 1D reduction:** Each row becomes a histogram problem
2. **Heights accumulate:** Consecutive 1s build up; 0 resets to 0
3. **Reuses histogram solution:** O(C) per row via monotonic stack

<br><br>

---

```code```
