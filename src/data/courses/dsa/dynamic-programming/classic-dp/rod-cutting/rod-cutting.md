Given a rod of length N and prices for each length 1..N, maximize revenue by cutting into pieces.

<br>

> **Key insight:** Unbounded knapsack: dp[len] = max(dp[len], price[i] + dp[len-i]) for each piece length i.

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

**Recurrence:** `dp[l] = max(price[i] + dp[l-i]) for i=1..l`

### Time Complexity: O(N²)
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
prices=[1,5,8,9,10,17,17,20], N=8 → cut into 2+6=5+17=22
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N²) | O(N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
