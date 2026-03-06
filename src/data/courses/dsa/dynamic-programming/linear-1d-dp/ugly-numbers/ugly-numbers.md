Find the nth ugly number. Ugly numbers are positive numbers whose prime factors are only 2, 3, or 5.

<br>

> Input:
> n = 10

> Output:
> 12

> Explanation:
> Sequence: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
> 10th ugly number is 12
> 
> **Key insight:** Generate ugly numbers by multiplying previous ugly numbers by 2, 3, 5.

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Not ideal for this problem - use tabulation**

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = ith ugly number
Use 3 pointers (i2, i3, i5)
dp[i] = min(dp[i2]*2, dp[i3]*3, dp[i5]*5)
```

```code```

### Time: O(n) | Space: O(n)

---
