0/1 Knapsack: given N items with weights and values, maximize value within weight capacity W. Each item used at most once.

<br>

> **Key insight:** dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i]). Either skip item or take it.

<br>

---

## Constraints
- Typical DP constraints

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

**Recurrence:** `dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i])`

### Time Complexity: O(N×W)
**Why?** Each state computed once.

### Space Complexity: O(W)

**Example walkthrough:**
```
items: wt=[1,3,4,5], val=[1,4,5,7], W=7 → dp[7]=9 (items 2+3: wt=3+4=7, val=4+5=9)
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
3. **Foundation:** Subset sum, partition, target sum are all knapsack variants
4. **1D optimization:** Process weights RIGHT to LEFT to avoid reusing items

<br><br>

---

```code```
