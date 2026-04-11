# Best Time to Buy and Sell Stock

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

**Example 1:**
```
Input: prices = [7,1,5,3,6,4]
Output: 5
```

Explanation:
> Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
> Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**
```
Input: prices = [7,6,4,3,1]
Output: 0
```

Explanation:
> In this case, no transactions are done and the max profit = 0.

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

## Solution 1: Recursive Approach (Brute Force)

**Intuition:**
At each day, we have two states: holding stock or not holding. If not holding, we can buy or skip. If holding, we can sell or hold. Try all possibilities and return maximum profit.

**Recurrence Relation:**
```
f(i, holding) = 0                                    if i = N
f(i, holding) = max(sell, hold)                     if holding = true
                where sell = prices[i] + f(i+1, false)
                      hold = f(i+1, true)
f(i, holding) = max(buy, skip)                      if holding = false
                where buy = -prices[i] + f(i+1, true)
                      skip = f(i+1, false)
```

**Algorithm:**
1. Base case: If reached end, return 0
2. If holding stock: try selling or holding
3. If not holding: try buying or skipping
4. Return maximum profit from all choices

### Time Complexity: O(2^N)
**Why exponential?**
- At each day, we make 2 recursive calls (two choices)
- Maximum depth = N (number of days)
- Total nodes in tree ≈ 2^N
- Example: N=10 → 2^10 = 1,024 calls

**Detailed breakdown:**
- Each state (i, holding) computed multiple times
- f(5, false) might be called from multiple paths
- Overlapping subproblems cause exponential redundancy
- No memoization = recompute same states repeatedly

### Space Complexity: O(N)
**Why?**
- Recursion stack depth = N (maximum calls)
- No additional data structures
- Maximum N recursive calls active simultaneously

**Problem:** Too slow for arrays longer than 20 elements.

> **Key Insight for Improvement:**
> We're solving the same (i, holding) states repeatedly. If we cache results, we can reduce time from exponential to linear.

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Store result of each (i, holding) state in a memo table. Before computing, check if already solved. This eliminates redundant calculations.

**Recurrence Relation:**
```
Same as recursive, but:
if (i, holding) in memo: return memo[i, holding]
else: compute, store in memo, return
```

**Algorithm:**
1. Create 2D memo dictionary/array
2. Before computing f(i, holding), check memo
3. If found, return cached value
4. Else compute recursively, store result, return

### Time Complexity: O(N)
**Why linear?**
- Total unique states = N × 2 (i from 0 to N-1, holding is true/false)
- Each state computed exactly once
- Subsequent lookups are O(1)
- Total work = 2N × O(1) = O(N)

**Detailed breakdown:**
- First call to f(i, holding): compute and cache → O(1) work
- All future calls: return memo[i, holding] → O(1)
- Total states = N × 2 = 2N
- Total time = 2N × O(1) = O(N)

**Improvement:** From O(2^N) to O(N)
- Example: N=20
- Recursive: 2^20 ≈ 1,048,576 operations
- Memoization: 20×2 = 40 operations

### Space Complexity: O(N)
**Why?**
- Memo table: N×2 entries → O(N)
- Recursion stack: O(N) depth
- Total: O(N) + O(N) = O(N)

**Breakdown:**
- Memo storage: 2N entries (two states per day)
- Stack space: Maximum N recursive calls active
- Total: O(N)

> **Key Insight for Improvement:**
> Memoization works but uses recursion. Can we solve iteratively? Yes - tabulation builds solution bottom-up.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Define dp[i][0] = max profit at day i not holding stock, dp[i][1] = max profit at day i holding stock. Build solution from end to start.

**DP State:**
```
dp[i][0] = maximum profit at day i when not holding stock
dp[i][1] = maximum profit at day i when holding stock
```

**Transition:**
```
dp[i][0] = max(-prices[i] + dp[i+1][1], dp[i+1][0])
           (buy today)              (skip)
dp[i][1] = max(prices[i] + dp[i+1][0], dp[i+1][1])
           (sell today)             (hold)
```

**Algorithm:**
1. Create dp table N+1 × 2, initialize dp[N] = [0, 0]
2. For each day i from N-1 down to 0:
   - dp[i][0] = max(buy, skip)
   - dp[i][1] = max(sell, hold)
3. Return dp[0][0] (start not holding)

### Time Complexity: O(N)
**Why?**
- Single loop: N iterations
- Each iteration: O(1) work
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Initialize table: O(N)
- Fill dp table: N iterations × O(1) = O(N)
- Total: O(N) + O(N) = O(N)

**Comparison with Memoization:**
- Same time complexity: O(N)
- But no recursion overhead (no function call stack)
- Iterative approach typically faster in practice

### Space Complexity: O(N)
**Why?**
- DP table: N×2 entries → O(N)
- No recursion stack (iterative)
- Total: O(N)

**Breakdown:**
- dp array: N×2 space
- Auxiliary variables: O(1)
- Total: O(N)

> **Key Insight for Improvement:**
> Notice we only need next day's values. Can we optimize space? Yes! We can track just min price seen so far and max profit.

<br>

---

## Solution 4: Space Optimized (One Pass)

**Intuition:**
Track minimum price seen so far. For each price, calculate profit if we sell today (price - min_price). Update max profit if current profit is higher.

**Algorithm:**
1. Initialize min_price = infinity, max_profit = 0
2. For each price:
   - Update min_price = min(min_price, price)
   - Update max_profit = max(max_profit, price - min_price)
3. Return max_profit

### Time Complexity: O(N)
**Why?**
- Single pass through array: N iterations
- Each iteration: O(1) work
- Total: N × O(1) = O(N)

**Detailed breakdown:**
- Process each price once: N iterations
- Two comparisons per iteration: O(1)
- Total: N × O(1) = O(N)

**Comparison with Tabulation:**
- Same time complexity: O(N)
- But simpler logic, no DP table needed
- Most intuitive and efficient solution

### Space Complexity: O(1)
**Why?**
- Only two variables: min_price and max_profit
- No arrays or data structures
- Total: O(1)

**Improvement:**
- Before (tabulation): O(N) space
- After (optimized): O(1) space
- Example: N=1,000,000
  - Before: 2,000,000 space units
  - After: 2 variables (1,000,000× reduction!)

**Why this works:**
- We only care about minimum price before current day
- Profit = current price - minimum price seen so far
- Track maximum profit across all days
- No need to store all previous states

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^N) | O(N) | Baseline - too slow |
| Memoization | O(N) | O(N) | Cache results - exponential to linear |
| Tabulation | O(N) | O(N) | Iterative - no recursion overhead |
| Space Optimized | O(N) | O(1) | Track min/max - optimal space |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache results
2. **Memoization → Tabulation:** Recursion overhead → iterative approach
3. **Tabulation → Space Optimized:** Only need min price → constant space

**When to use each:**
- **Memoization:** Natural recursion, state machine approach
- **Tabulation:** Want iterative DP solution
- **Space Optimized:** Most efficient, single pass with O(1) space

> **Final Complexity:** O(N) time, O(1) space

<br>
<br>

---

```code```
