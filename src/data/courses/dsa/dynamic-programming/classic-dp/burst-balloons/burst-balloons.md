Burst balloons to maximize coins. Bursting balloon i gives nums[left]×nums[i]×nums[right].

<br>

> **Key insight:** Think BACKWARDS: which balloon to burst LAST in range [i,j]? dp[i][j] = max(dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1]) for k in [i,j].

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **Single balloon:** just burst it
2. **Two balloons:** try both orders
3. **All same values**
4. **Virtual boundary balloons (value 1)**

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

**Recurrence:** `dp[i][j] = max(dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j])`

### Time Complexity: O(N³)
**Why?** Each state computed once.

### Space Complexity: O(N²)

**Example walkthrough:**
```
nums=[3,1,5,8] → 167. Burst order: 1, then 5, then 3, then 8.
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N³) | O(N²) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible


<br><br>

---

```code```
