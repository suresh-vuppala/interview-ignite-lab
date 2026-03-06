Find maximum sum of non-adjacent elements in array (same as House Robber).

<br>

> Input:
> arr = [5, 1, 3, 8, 2]

> Output:
> 15

> Explanation:
> Select 5, 8, 2 (non-adjacent) = 15
> 
> **Key insight:** Same as House Robber problem.

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
maxSum(i) = max(arr[i] + maxSum(i-2), maxSum(i-1))
```

```code```

### Time: O(n) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = max sum using elements 0..i
dp[i] = max(arr[i] + dp[i-2], dp[i-1])
```

```code```

### Time: O(n) | Space: O(1) optimized

---
