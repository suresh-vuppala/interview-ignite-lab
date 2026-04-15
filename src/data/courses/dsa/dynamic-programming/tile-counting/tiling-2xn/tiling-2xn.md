Fill a 2×N board with 1×2 tiles (horizontal or vertical). Count the number of ways.

<br>

> Input: n=4
> Output: 5
> **Key insight:** dp[i] = dp[i-1] + dp[i-2]. Place vertical tile (leaves 2×(n-1)) or two horizontal tiles (leaves 2×(n-2)). Same as Fibonacci!

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **N = 0:** 1 way (empty)
2. **N = 1:** 1 way
3. **Large N:** overflow
4. **Follows Fibonacci pattern**

<br>

---

## Solution 1: Recursion (Brute Force)

**Intuition:**
The most straightforward approach — try all possibilities and check each one.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: DP — Bottom-up Fibonacci

**Recurrence:** `dp[i] = dp[i-1] + dp[i-2]`

**Algorithm:** Bottom-up Fibonacci

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
dp[1]=1, dp[2]=2, dp[3]=3, dp[4]=5
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(2^N) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(1) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array


<br><br>

---

```code```
