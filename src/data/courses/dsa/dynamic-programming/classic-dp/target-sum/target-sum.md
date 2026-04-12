Assign + or - to each number to reach a target sum. Count the number of ways.

<br>

> **Key insight:** Reduce to subset sum: find subset with sum = (total+target)/2. Count subsets with that sum.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion

> **Drawback:** Overlapping subproblems.

> **Key Insight for Improvement:** Recurrence: `dp[j] += dp[j-nums[i]] — count variant of subset sum`

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[j] += dp[j-nums[i]] — count variant of subset sum`

### Time Complexity: O(N×sum)
**Why?** Each state computed once.

### Space Complexity: O(sum)

**Example walkthrough:**
```
nums=[1,1,1,1,1], target=3 → 5 ways
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N×sum) | O(sum) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
