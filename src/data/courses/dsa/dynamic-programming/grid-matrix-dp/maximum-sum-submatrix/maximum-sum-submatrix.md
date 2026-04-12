Find the submatrix with maximum sum in a 2D matrix.

<br>

> matrix=[[1,2,-1],[-3,4,2],[1,-1,3]] → max sum submatrix
> **Key insight:** Fix left and right columns. For each pair, compute row sums → 1D array. Apply Kadane's on that array. O(N²×M) total.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(M²×N²)

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `Kadane's on compressed column sums`

<br>

---

## Solution 2: DP — Fix columns + Kadane's

**Recurrence:** `Kadane's on compressed column sums`

### Time Complexity: O(N²×M) or O(M²×N)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(M)

**Example walkthrough:**
```
Fix cols l,r. Row sum = prefix[r]-prefix[l-1]. Kadane's on row sums.
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(M²×N²) | O(N) stack |
| Memoization | O(N²×M) or O(M²×N) | Same as tabulation |
| Tabulation | O(N²×M) or O(M²×N) | O(M) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
