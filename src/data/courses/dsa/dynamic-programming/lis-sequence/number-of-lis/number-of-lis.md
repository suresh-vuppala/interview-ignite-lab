Count the number of longest increasing subsequences.

<br>

> **Key insight:** Track both length dp[i] and count cnt[i]. When dp[j]+1 == dp[i]: cnt[i] += cnt[j]. When dp[j]+1 > dp[i]: cnt[i] = cnt[j].

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **All same elements:** every element is LIS of length 1 → count = N
2. **Strictly increasing:** count = 1
3. **Multiple subsequences of same max length**

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

**Recurrence:** `dp[i]=max len ending at i, cnt[i]=count of LIS ending at i`

### Time Complexity: O(N²)
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
nums=[1,3,5,4,7] → LIS length=4, count=2 ([1,3,5,7] and [1,3,4,7])
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
