Break a positive integer n into at least two positive integers that sum to n. Maximize the product.

<br>

> Input: n=10
> Output: 36 (3+3+4=10, 3×3×4=36)
> **Key insight:** dp[i] = max over j of (j × max(i-j, dp[i-j])). For each split j, either use (i-j) directly or break it further.

<br>

---

## Constraints
- Typical DP constraints

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

## Solution 2: DP — Bottom-up DP

**Recurrence:** `dp[i] = max(j * max(i-j, dp[i-j])) for j=1..i-1`

**Algorithm:** Bottom-up DP

### Time Complexity: O(N²)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(N)

**Example walkthrough:**
```
dp[2]=1, dp[3]=2, dp[4]=4, dp[5]=6, dp[6]=9, dp[7]=12, dp[8]=18, dp[9]=27, dp[10]=36
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(N²) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N²) | O(N) | Cache computed states |
| Tabulation | O(N²) | O(N) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array
4. **Math insight:** Always break into 3s (except remainder 1→use 4, remainder 2→keep 2)

<br><br>

---

```code```
