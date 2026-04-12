Find minimum number of scalar multiplications to multiply a chain of matrices.

<br>

> **Key insight:** dp[i][j] = min(dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j]) for all k in [i,j). Try every split point.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[i][j] = min(dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j])`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i][j] = min(dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j])`

### Time Complexity: O(N³)
**Why?** Each state computed once.

### Space Complexity: O(N²)

**Example walkthrough:**
```
dims=[10,20,30,40]: dp[1][3] = min splits. Optimal: (A×B)×C or A×(B×C)
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N³) | O(N²) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
