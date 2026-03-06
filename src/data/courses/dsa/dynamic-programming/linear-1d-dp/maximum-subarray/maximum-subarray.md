Find the contiguous subarray with the largest sum (Kadane's Algorithm).

<br>

> Input:
> nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

> Output:
> 6

> Explanation:
> Subarray [4, -1, 2, 1] has sum = 6
> 
> **Key insight:** At each position, either extend current subarray or start new.

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
maxEndingHere(i) = max(nums[i], nums[i] + maxEndingHere(i-1))
maxSoFar = max of all maxEndingHere(i)
```

```code```

### Time: O(n) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = max sum ending at index i
dp[i] = max(nums[i], nums[i] + dp[i-1])
result = max(dp)
```

```code```

### Time: O(n) | Space: O(1) optimized (Kadane's)

---
