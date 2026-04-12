Find minimum path sum from top to bottom of a triangle. Each step can go to adjacent numbers on the row below.

<br>

> triangle=[[2],[3,4],[6,5,7],[4,1,8,3]] → 11 (2→3→5→1)
> **Key insight:** Bottom-up: start from last row. dp[j] = triangle[i][j] + min(dp[j], dp[j+1]). Work upward.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `dp[j] = triangle[i][j] + min(dp[j], dp[j+1])`

<br>

---

## Solution 2: DP — Bottom-up on last row

**Recurrence:** `dp[j] = triangle[i][j] + min(dp[j], dp[j+1])`

### Time Complexity: O(N²)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(N)

**Example walkthrough:**
```
Bottom row: [4,1,8,3]. Row 2: [6+1,5+1,7+3]=[7,6,10]. Row 1: [3+6,4+6]=[9,10]. Row 0: [2+9]=11
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(2^N) | O(N) stack |
| Memoization | O(N²) | Same as tabulation |
| Tabulation | O(N²) | O(N) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
