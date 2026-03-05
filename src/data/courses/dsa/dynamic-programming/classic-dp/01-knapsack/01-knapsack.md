Given weights and values of n items and a knapsack capacity W, find the maximum value you can obtain. Each item can be taken at most once (0 or 1 choice).

<br>

> Input:
> weights = [1, 3, 4, 5], values = [1, 4, 5, 7], W = 7

> Output:
> 9

> Explanation:
> Take items with weights [3, 4] and values [4, 5]
> Total weight: 3 + 4 = 7 ≤ W
> Total value: 4 + 5 = 9 (maximum)
> 
> **Key insight:** For each item, choose to include or exclude to maximize value.

<br>

---

## Solution 1: Memoization (Top-Down DP)

**Recurrence Relation:**
```
if wt[i] <= W:
    knapsack(i, W) = max(val[i] + knapsack(i-1, W-wt[i]), knapsack(i-1, W))
else:
    knapsack(i, W) = knapsack(i-1, W)
Base: knapsack(0, *) = 0, knapsack(*, 0) = 0
```

**Algorithm:**
1. For item i with capacity W:
   - If weight fits: max(include, exclude)
   - If doesn't fit: exclude
2. Store in memo[i][W]

**Key insight:** Each item has binary choice - take or leave.

```code```

<br>

### Time Complexity: O(n × W)
- n × W subproblems
- Each computed once

### Space Complexity: O(n × W)
- Memo table: O(n × W)
- Recursion stack: O(n)

<br>

---

## Solution 2: Tabulation (Bottom-Up DP)

**DP State:**
```
dp[i][w] = max value using items 0..i-1 with capacity w
```

**Transition:**
```
if wt[i-1] <= w:
    dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w])
else:
    dp[i][w] = dp[i-1][w]
```

**Algorithm:**
1. Create (n+1) × (W+1) dp table
2. Initialize first row and column to 0
3. Fill table using transition
4. Return dp[n][W]

```code```

<br>

### Time Complexity: O(n × W)
- Nested loops: n × W iterations

### Space Complexity: O(n × W)
- DP table: O(n × W)

**Space Optimization: O(W)**
- Only need previous row
- Use 1D array, iterate backwards

<br>

---

## Comparison

| Approach | Time | Space | Pros | Cons |
|----------|------|-------|------|------|
| Memoization | O(n×W) | O(n×W) | Intuitive | Stack overhead |
| Tabulation | O(n×W) | O(n×W) | Iterative | Must solve all |
| Optimized | O(n×W) | O(W) | Space efficient | Can't reconstruct |

**Note:** This is pseudo-polynomial time (depends on W value, not its bit length).

**Applications:**
- Resource allocation
- Budget optimization
- Cargo loading
- Portfolio selection

> **Time Complexity:** O(n × W)
> **Space Complexity:** O(n × W) or O(W) optimized

<br>
<br>

---
