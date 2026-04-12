Find the nth ugly number. Ugly numbers have only 2, 3, 5 as prime factors. Sequence: 1,2,3,4,5,6,8,9,10,12...

<br>

> Input: n=10
> Output: 12
> **Key insight:** Three pointers for factors 2, 3, 5. Next ugly = min(ugly[i2]*2, ugly[i3]*3, ugly[i5]*5). Advance the pointer(s) that produced the min.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(N log N) with heap

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = min(dp[i2]*2, dp[i3]*3, dp[i5]*5)

<br>

---

## Solution 2: DP — Three-pointer merge

**Recurrence:** `dp[i] = min(dp[i2]*2, dp[i3]*3, dp[i5]*5)`

**Algorithm:** Three-pointer merge

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(N)

**Example walkthrough:**
```
i2=i3=i5=0. dp=[1,2,3,4,5,6,8,9,10,12]
Each step: take min of 3 candidates, advance matching pointers
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Recursion | O(N log N) with heap | O(N) stack | Brute force, overlapping subproblems |
| Memoization | O(N) | O(N) | Cache computed states |
| Tabulation | O(N) | O(N) | Bottom-up, possible space optimization |

**Key Insights:**
1. **Identify recurrence:** Express dp[i] in terms of smaller subproblems
2. **Base cases:** Starting values that don't depend on other states
3. **Space optimization:** If dp[i] only depends on dp[i-1] and dp[i-2], use two variables instead of array


<br><br>

---

```code```
