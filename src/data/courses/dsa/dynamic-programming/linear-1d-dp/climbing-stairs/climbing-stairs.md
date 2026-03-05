You are climbing a staircase with n steps. You can climb 1 or 2 steps at a time. How many distinct ways can you reach the top?

<br>

> Input:
> n = 5

> Output:
> 8

> Explanation:
> Ways to reach step 5:
> 1. 1+1+1+1+1
> 2. 1+1+1+2
> 3. 1+1+2+1
> 4. 1+2+1+1
> 5. 2+1+1+1
> 6. 1+2+2
> 7. 2+1+2
> 8. 2+2+1
> 
> **Key insight:** To reach step i, you can come from step i-1 or i-2.

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence Relation:**
```
ways(n) = ways(n-1) + ways(n-2)
Base: ways(0) = 1, ways(1) = 1
```

**Algorithm:**
1. Start from n, recursively solve subproblems
2. Store results in memo to avoid recomputation
3. Return memo[n]

**Key insight:** Same as Fibonacci - each step depends on previous two.

```code```

<br>

### Time Complexity: O(n)
- Each subproblem computed once
- Memoization prevents recomputation
- Total: n subproblems × O(1) = O(n)

### Space Complexity: O(n)
- Memo array: O(n)
- Recursion stack: O(n)

<br>

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i] = number of ways to reach step i
```

**Transition:**
```
dp[i] = dp[i-1] + dp[i-2]
```

**Algorithm:**
1. Create dp array of size n+1
2. Initialize: dp[0] = 1, dp[1] = 1
3. Fill dp[i] for i from 2 to n
4. Return dp[n]

```code```

<br>

### Time Complexity: O(n)
- Single loop from 2 to n
- Each iteration: O(1)

### Space Complexity: O(n)
- DP array: O(n)

**Space Optimization: O(1)**
- Only need last 2 values
- Use two variables instead of array

<br>

---

## Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Memoization | O(n) | O(n) | Intuitive, solves only needed | Recursion overhead |
| Tabulation | O(n) | O(n) | Iterative, no stack | Must solve all subproblems |
| Optimized | O(n) | O(1) | Minimal space | Less readable |

> **Time Complexity:** O(n) for both approaches
> **Space Complexity:** O(n) or O(1) with optimization

<br>
<br>

---
