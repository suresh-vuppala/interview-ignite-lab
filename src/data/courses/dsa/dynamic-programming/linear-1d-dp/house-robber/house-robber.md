You are a robber planning to rob houses along a street. Each house has money, but adjacent houses have security systems. If you rob two adjacent houses, the alarm will trigger. Find the maximum money you can rob.

<br>

> Input:
> nums = [2, 7, 9, 3, 1]

> Output:
> 12

> Explanation:
> Rob house 0 (2) + house 2 (9) + house 4 (1) = 12
> Cannot rob: house 0 + house 1 (adjacent)
> Cannot rob: house 1 + house 2 (adjacent)
> 
> **Key insight:** At each house, choose max of (rob current + skip previous) or (skip current).

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence Relation:**
```
rob(i) = max(nums[i] + rob(i-2), rob(i-1))
Base: rob(0) = nums[0], rob(1) = max(nums[0], nums[1])
```

**Algorithm:**
1. For house i, two choices:
   - Rob it: nums[i] + rob(i-2)
   - Skip it: rob(i-1)
2. Take maximum
3. Store in memo

**Key insight:** Can't rob adjacent, so if rob current, must skip previous.

```code```

<br>

### Time Complexity: O(n)
- Each house computed once
- Memoization prevents recomputation

### Space Complexity: O(n)
- Memo array: O(n)
- Recursion stack: O(n)

<br>

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = maximum money robbing houses 0 to i
```

**Transition:**
```
dp[i] = max(nums[i] + dp[i-2], dp[i-1])
```

**Algorithm:**
1. Create dp array
2. Initialize: dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
3. For i from 2 to n-1:
   - dp[i] = max(nums[i] + dp[i-2], dp[i-1])
4. Return dp[n-1]

```code```

<br>

### Time Complexity: O(n)
- Single pass through houses

### Space Complexity: O(n)
- DP array: O(n)

**Space Optimization: O(1)**
- Only need last 2 values
- Use two variables: prev2, prev1

<br>

---

## Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Memoization | O(n) | O(n) | Intuitive | Stack overhead |
| Tabulation | O(n) | O(n) | Iterative | Must solve all |
| Optimized | O(n) | O(1) | Minimal space | Less clear |

**Applications:**
- Resource allocation with constraints
- Scheduling with conflicts
- Maximum sum non-adjacent elements

> **Time Complexity:** O(n)
> **Space Complexity:** O(n) or O(1) optimized

<br>
<br>

---

```python
class Solution:
    # Memoization
    def robMemo(self, nums):
        memo = {}
        def dp(i):
            if i < 0: return 0
            if i in memo: return memo[i]
            memo[i] = max(nums[i] + dp(i-2), dp(i-1))
            return memo[i]
        return dp(len(nums)-1)
    
    # Tabulation
    def rob(self, nums):
        if not nums: return 0
        if len(nums) == 1: return nums[0]
        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        return dp[-1]
```
