Find minimum number of coins to make amount. Unlimited supply of each coin.

<br>

> **Key insight:** dp[amount] = min(dp[amount], dp[amount-coin]+1). Try each coin, take the one giving fewest total coins.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **Amount = 0:** 0 coins
2. **No valid combination:** return -1
3. **Single coin type**
4. **Coin value = 1:** amount coins needed**

<br>

---

## Solution 1: Recursion

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(N²)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i] = min(dp[i-coin] + 1) for each coin`

### Time Complexity: O(amount × coins)
**Why?** Each state computed once.

### Space Complexity: O(amount)

**Example walkthrough:**
```
coins=[1,5,11], amount=15 → dp[15]=3 (5+5+5)
Greedy would pick 11+1+1+1+1=5 coins — WRONG! DP finds optimal.
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(amount × coins) | O(amount) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **Greedy fails:** coins=[1,5,11], amount=15. Greedy=5, DP=3
4. **FAANG classic:** Tests unbounded knapsack understanding

<br><br>

---

```code```
