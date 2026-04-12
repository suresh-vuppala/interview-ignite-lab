Count permutations of N elements where no element appears in its original position.

<br>

> Input: n=3
> Output: 2 (231, 312)
> **Key insight:** dp[i] = (i-1) * (dp[i-1] + dp[i-2]). Element 1 swaps with one of (i-1) elements. After swap: either derangement of remaining (dp[i-1] if 3-cycle+) or simpler (dp[i-2] if direct swap).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(N!)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = (i-1) * (dp[i-1] + dp[i-2])

<br>

---

## Solution 2: DP — Bottom-up

**Recurrence:** `dp[i] = (i-1) * (dp[i-1] + dp[i-2])`

**Algorithm:** Bottom-up

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
dp[1]=0, dp[2]=1, dp[3]=2*(1+0)=2, dp[4]=3*(2+1)=9, dp[5]=4*(9+2)=44
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(N!) | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(1) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array


<br><br>

---

```code```
