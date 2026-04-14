Given K eggs and N floors, find minimum number of trials to find the critical floor.

<br>

> **Key insight:** dp[k][n] = 1 + min(max(dp[k-1][i-1], dp[k][n-i])) for i=1..n. Binary search optimization possible.

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

**Recurrence:** `dp[k][n] = 1 + min over i of max(dp[k-1][i-1], dp[k][n-i])`

### Time Complexity: O(K×N×logN) with binary search
**Why?** Each state computed once.

### Space Complexity: O(K×N)

**Example walkthrough:**
```
K=2, N=10 → 4 trials. Optimal strategy: drop from floors 4, 7, 9, 10
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(K×N×logN) with binary search | O(K×N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **Binary search optimization:** For fixed k, the break/nobreak functions are monotonic → binary search for optimal floor

<br><br>

---

```code```
