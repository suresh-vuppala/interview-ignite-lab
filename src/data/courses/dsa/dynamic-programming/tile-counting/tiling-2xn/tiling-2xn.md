Find the number of ways to tile a 2×N board using 1×2 tiles. Tiles can be placed horizontally or vertically.

<br>

> Input:
> n = 3

> Output:
> 3

> Explanation:
> Three ways to tile 2×3 board:
> 1. Three horizontal tiles (stacked)
> 2. One vertical + two horizontal
> 3. Two horizontal + one vertical
> 
> **Key insight:** Each column can be filled with 1 vertical tile or 2 horizontal tiles.

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
At position i, we can either place 1 vertical tile (covers 1 column) or 2 horizontal tiles (covers 1 column). This gives us f(i) = f(i-1) + f(i-2).

**Recurrence Relation:**
```
f(n) = f(n-1) + f(n-2)
Base: f(0) = 1, f(1) = 1
```

**Algorithm:**
1. Base case: If n = 0, return 1 (empty board)
2. Base case: If n = 1, return 1 (one vertical tile)
3. Recursively compute: f(n-1) + f(n-2)

### Time Complexity: O(2^n)
**Why exponential?**
- Each call makes 2 recursive calls
- Recursion tree depth = n
- Total nodes ≈ 2^n
- f(5) computed multiple times from different paths

**Detailed breakdown:**
- f(n) calls f(n-1) and f(n-2)
- f(n-1) calls f(n-2) and f(n-3)
- f(n-2) computed twice already
- Overlapping subproblems grow exponentially

### Space Complexity: O(n)
**Why?**
- Recursion stack depth = n
- Maximum n recursive calls active
- No additional data structures

**Problem:** Exponential time due to repeated calculations.

> **Key Insight for Improvement:**
> We're solving f(i) multiple times. Store results in memo to avoid recomputation and reduce from O(2^n) to O(n).

<br>

---

## Solution 2: Memoization (Top-Down DP)

**Intuition:**
Cache results of f(i) in a memo table. When f(i) is needed again, return cached value instead of recomputing.

**Recurrence Relation:**
```
Same as recursive, but check memo first:
if i in memo: return memo[i]
else: compute, store, return
```

**Algorithm:**
1. Create memo dictionary
2. Check memo before computing
3. Compute f(i-1) + f(i-2)
4. Store in memo and return

### Time Complexity: O(n)
**Why linear?**
- Total unique subproblems = n
- Each computed exactly once
- Subsequent calls return memo[i] in O(1)
- Total: n × O(1) = O(n)

**Detailed breakdown:**
- First call to f(i): compute and cache → O(1)
- All future calls to f(i): return memo[i] → O(1)
- Total subproblems = n
- Total time = O(n)

**Improvement:** From O(2^n) to O(n)
- Example: n = 20
- Recursive: 2^20 ≈ 1,000,000 operations
- Memoization: 20 operations

### Space Complexity: O(n)
**Why?**
- Memo table: n entries → O(n)
- Recursion stack: O(n) depth
- Total: O(n)

> **Key Insight for Improvement:**
> Memoization uses recursion stack. Can we solve iteratively? Yes - tabulation builds from base cases upward without recursion.

<br>

---

## Solution 3: Tabulation (Bottom-Up DP)

**Intuition:**
Build solution iteratively from f(0) to f(n). Each value depends only on previous two values.

**DP State:**
```
dp[i] = number of ways to tile 2×i board
```

**Transition:**
```
dp[i] = dp[i-1] + dp[i-2]
```

**Algorithm:**
1. Create dp array of size n+1
2. Initialize: dp[0] = 1, dp[1] = 1
3. For i from 2 to n: dp[i] = dp[i-1] + dp[i-2]
4. Return dp[n]

### Time Complexity: O(n)
**Why?**
- Single loop from 2 to n
- Each iteration: O(1) work
- Total: n × O(1) = O(n)

**Comparison with Memoization:**
- Same time: O(n)
- No recursion overhead
- Faster in practice

### Space Complexity: O(n)
**Why?**
- DP array: n+1 entries → O(n)
- No recursion stack
- Total: O(n)

> **Key Insight for Improvement:**
> dp[i] only depends on dp[i-1] and dp[i-2]. We don't need entire array - just last 2 values! Use two variables for O(1) space.

<br>

---

## Solution 4: Space Optimized

**Intuition:**
Since we only need previous 2 values, use two variables instead of array.

**Algorithm:**
1. Initialize: prev2 = 1, prev1 = 1
2. For i from 2 to n:
   - curr = prev1 + prev2
   - prev2 = prev1
   - prev1 = curr
3. Return prev1

### Time Complexity: O(n)
**Why unchanged?**
- Same iteration pattern
- Space optimization doesn't affect time

### Space Complexity: O(1)
**Why optimal?**
- Only 3 variables: prev2, prev1, curr
- No array or recursion stack
- Constant space

**Improvement:**
- Before: O(n) space
- After: O(1) space
- Perfect for large n

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursive | O(2^n) | O(n) | Baseline - exponential |
| Memoization | O(n) | O(n) | Cache results - exponential to linear |
| Tabulation | O(n) | O(n) | Remove recursion - cleaner |
| Space Optimized | O(n) | O(1) | Two variables - optimal |

**Key Insights:**
1. **Recursive → Memoization:** Overlapping subproblems → cache
2. **Memoization → Tabulation:** Recursion overhead → iterative
3. **Tabulation → Optimized:** Only need last 2 values → variables

**Pattern Recognition:**
- This is Fibonacci pattern: f(n) = f(n-1) + f(n-2)
- Same as Climbing Stairs problem
- Common in counting problems

> **Final Complexity:** O(n) time, O(1) space

<br>
<br>

---

```code```
