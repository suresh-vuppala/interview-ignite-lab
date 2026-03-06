Houses are arranged in a circle. You cannot rob two adjacent houses. Find maximum money you can rob.

<br>

> Input:
> nums = [2, 3, 2]

> Output:
> 3

> Explanation:
> Cannot rob house 0 and 2 (adjacent in circle)
> Rob house 1: value = 3
> 
> **Key insight:** Either rob houses [0..n-2] OR [1..n-1], take max.

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence:**
```
rob(nums) = max(robLinear(0, n-2), robLinear(1, n-1))
robLinear(i) = max(nums[i] + rob(i-2), rob(i-1))
```

```code```

### Time: O(n) | Space: O(n)

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
Run House Robber I twice:
1. On nums[0..n-2]
2. On nums[1..n-1]
Return max of both
```

```code```

### Time: O(n) | Space: O(1) optimized

---
