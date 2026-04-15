Merge two sorted arrays into one.

<br>

> **Key insight:** Two pointers, compare heads, append smaller.

<br>

---

## Constraints
- 0 ≤ N, M ≤ 50

<br>

---

## All Possible Edge Cases
1. **One or both empty
2. **No interleaving needed
3. **All elements in one < all in other**

<br>

---

## Solution 1: Brute Force

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

## Solution 2: Optimal

**Recurrence/Approach:** `Two-pointer merge`

### Time Complexity: O(N+M)
**Why?** Each element/state processed efficiently.

### Space Complexity: O(N+M)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Brute | Higher | Varies |
| Optimal | O(N+M) | O(N+M) |

**Key Insights:**
1. Core technique applied correctly
2. Edge cases handled
3. Space optimization where possible

<br><br>

---

```code```
