Unbounded Knapsack: same as 0/1 but each item can be used unlimited times.

<br>

> **Key insight:** Process weights LEFT to RIGHT (allows reuse). dp[w] = max(dp[w], dp[w-wt[i]] + val[i]).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **Same as 0/1 but items reusable**
2. **Single item repeated to fill**
3. **Lightest item doesn't fit:** profit = 0

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

**Recurrence:** `dp[w] = max(dp[w], dp[w-wt[i]] + val[i]) — LEFT to RIGHT`

### Time Complexity: O(N×W)
**Why?** Each state computed once.

### Space Complexity: O(W)

**Example walkthrough:**
```
Same as 0/1 but iterate LEFT to RIGHT to allow repeated items
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N×W) | O(W) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **Key difference from 0/1:** Direction of inner loop. Left-to-right = reuse allowed

<br><br>

---

```code```
