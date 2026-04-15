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

## All Possible Edge Cases
1. **Leading zero: "0..."** → 0 ways
2. **Contains "00":** 0 ways
3. **All 1s and 2s:** maximum branching
4. **Single digit**
5. **"10" and "20":** only one decoding each

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
