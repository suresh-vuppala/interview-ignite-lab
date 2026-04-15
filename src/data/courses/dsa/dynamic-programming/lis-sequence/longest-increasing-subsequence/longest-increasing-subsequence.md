Find length of the longest strictly increasing subsequence.

<br>

> **Key insight:** O(N²) DP: dp[i] = max(dp[j]+1) for all j<i where nums[j]<nums[i]. O(N log N): maintain sorted tails array, binary search for insertion point.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **Already sorted:** LIS = N
2. **Reverse sorted:** LIS = 1
3. **All equal:** LIS = 1
4. **Single element**

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

**Recurrence:** `dp[i] = 1 + max(dp[j]) for j<i where nums[j]<nums[i]`

### Time Complexity: O(N log N) with patience sorting
**Why?** Each state computed once.

### Space Complexity: O(N)

**Example walkthrough:**
```
nums=[10,9,2,5,3,7,101,18] → LIS=4 ([2,3,7,101] or [2,5,7,101])
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | Exponential | O(N) stack |
| DP | O(N log N) with patience sorting | O(N) |

**Key Insights:**
1. Identify states, transitions, base cases
2. Space optimization when possible
3. **O(N log N) trick:** Maintain array of smallest tail elements. Binary search for position.
4. **FAANG critical:** Top-10 DP problem

<br><br>

---

```code```
