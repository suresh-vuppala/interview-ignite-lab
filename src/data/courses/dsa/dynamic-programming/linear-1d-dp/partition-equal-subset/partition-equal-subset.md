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

## Constraints

- `0 ≤ n ≤ 10⁴`
- `Values fit in 32-bit integer`
- `DP state space fits in memory`

<br>

---

## All Possible Edge Cases

1. **n = 0 or empty input:** Base case — return 0 or empty
2. **n = 1:** Single element — trivial case
3. **All same elements:** Check if pattern still applies
4. **Maximum constraints:** Verify time complexity handles worst case
5. **Negative values (if applicable):** Affects min/max DP transitions
6. **Result requires modular arithmetic:** Use MOD = 10⁹ + 7 to prevent overflow

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
canPartition(i, sum) = canPartition(i-1, sum) || canPartition(i-1, sum-nums[i])
```



### Time: O(n × sum) | Space: O(n × sum)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i][j] = can make sum j using first i elements
dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
```



### Time: O(n × sum) | Space: O(sum) optimized

---

---

```code```
