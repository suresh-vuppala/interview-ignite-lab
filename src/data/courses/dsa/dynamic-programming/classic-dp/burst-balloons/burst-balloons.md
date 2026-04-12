Burst balloons to maximize coins. Bursting balloon i gives nums[left]×nums[i]×nums[right].

<br>

> **Key insight:** Think BACKWARDS: which balloon to burst LAST in range [i,j]? dp[i][j] = max(dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]) for k in [i,j].

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[i][j] = max(dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j])`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i][j] = max(dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j])`

### Time Complexity: O(N³)
**Why?** Each state computed once.

### Space Complexity: O(N²)

**Example walkthrough:**
```
nums=[3,1,5,8] → 167. Burst order: 1, then 5, then 3, then 8.
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
