A message of digits can be decoded (A=1..Z=26). Count total ways to decode.

<br>

> Input: s='226'
> Output: 3 ('BZ'=2,26, 'VF'=22,6, 'BBF'=2,2,6)
> **Key insight:** dp[i] = (dp[i-1] if s[i] valid single) + (dp[i-2] if s[i-1..i] valid pair 10-26).

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## Solution 1: Recursion (Brute Force)

### Time Complexity: O(2^N)

> **Drawback:** Overlapping subproblems cause exponential recomputation. The same state is computed many times.

> **Key Insight for Improvement:** Memoize computed states (top-down) or build bottom-up (tabulation). Recurrence: dp[i] = dp[i-1]*(valid single) + dp[i-2]*(valid pair)

<br>

---

## Solution 2: DP — Bottom-up with two variables

**Recurrence:** `dp[i] = dp[i-1]*(valid single) + dp[i-2]*(valid pair)`

**Algorithm:** Bottom-up with two variables

### Time Complexity: O(N)
**Why?** Each state computed exactly once. Total states × O(1) per state transition.

**Detailed breakdown:** Depends on input size, but each state visited once.

### Space Complexity: O(1)

**Example walkthrough:**
```
s='226': dp[0]=1('B'), dp[1]=2('BB','V'), dp[2]=3('BBF','VF','BZ')
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
