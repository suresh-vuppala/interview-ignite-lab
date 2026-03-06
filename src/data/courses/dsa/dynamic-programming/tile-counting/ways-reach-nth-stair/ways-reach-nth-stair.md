Find the number of ways to reach the nth stair. You can climb 1, 2, or 3 steps at a time.

<br>

> Input:
> n = 4

> Output:
> 7

> Explanation:
> Seven ways to reach stair 4:
> 1. 1+1+1+1
> 2. 1+1+2
> 3. 1+2+1
> 4. 2+1+1
> 5. 2+2
> 6. 1+3
> 7. 3+1
> 
> **Key insight:** To reach stair i, you can come from i-1, i-2, or i-3.

<br>

---

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At stair i, we can reach it from i-1 (1 step), i-2 (2 steps), or i-3 (3 steps). Total ways = sum of ways from these three positions.

**Recurrence Relation:**
```
f(n) = f(n-1) + f(n-2) + f(n-3)
Base: f(0) = 1, f(1) = 1, f(2) = 2
```

**Algorithm:**
1. Base cases: f(0)=1, f(1)=1, f(2)=2
2. Recursively compute: f(n-1) + f(n-2) + f(n-3)

### Time Complexity: O(3^n)
**Why exponential?**
- Each call makes 3 recursive calls
- Recursion tree has branching factor 3
- Depth = n
- Total nodes ≈ 3^n

### Space Complexity: O(n)
- Recursion stack depth = n

> **Key Insight for Improvement:**
> We're computing f(i) multiple times. Memoize results to reduce from O(3^n) to O(n).

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Cache results to avoid recomputation.

**Algorithm:**
1. Create memo dictionary
2. Check memo before computing
3. Store and return result

### Time Complexity: O(n)
- Each of n subproblems computed once

### Space Complexity: O(n)
- Memo table + recursion stack

> **Key Insight for Improvement:**
> Remove recursion overhead with iterative tabulation.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = ways to reach stair i
```

**Transition:**
```
dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
```

**Algorithm:**
1. Initialize: dp[0]=1, dp[1]=1, dp[2]=2
2. For i from 3 to n: dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
3. Return dp[n]

### Time Complexity: O(n)
### Space Complexity: O(n)

> **Key Insight for Improvement:**
> Only need last 3 values. Use three variables for O(1) space.

<br>

---

## Solution 4: Space Optimized

**Algorithm:**
1. Use three variables: prev3, prev2, prev1
2. Update in sliding window fashion

### Time Complexity: O(n)
### Space Complexity: O(1)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(3^n) | O(n) | Baseline |
| Memoization | O(n) | O(n) | Cache results |
| Tabulation | O(n) | O(n) | Remove recursion |
| Space Optimized | O(n) | O(1) | Three variables |

> **Final Complexity:** O(n) time, O(1) space

<br>
<br>

---

```code```
