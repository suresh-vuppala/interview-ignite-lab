Determine if array can be partitioned into two subsets with equal sum (Subset Sum variant).

<br>

> Input:
> nums = [1, 5, 11, 5]

> Output:
> true

> Explanation:
> [1, 5, 5] and [11] both sum to 11
> 
> **Key insight:** Find if subset with sum = total/2 exists (0/1 Knapsack).

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
canPartition(i, sum) = canPartition(i-1, sum) || canPartition(i-1, sum-nums[i])
```

```code```

### Time: O(n × sum) | Space: O(n × sum)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i][j] = can make sum j using first i elements
dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
```

```code```

### Time: O(n × sum) | Space: O(sum) optimized

---
