Find the submatrix with maximum sum in a 2D matrix.

<br>

> matrix=[[1,2,-1],[-3,4,2],[1,-1,3]] → max sum submatrix
> **Key insight:** Fix left and right columns. For each pair, compute row sums → 1D array. Apply Kadane's on that array. O(N²×M) total.

<br>

---

## Constraints
- Typical DP constraints

<br>

---

## All Possible Edge Cases
1. **1×1 matrix:** that element
2. **All positive:** entire matrix
3. **All negative:** least negative element
4. **Mixed positive/negative**

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

### Time Complexity: O(M²×N²)
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

## Solution 2: DP — Fix columns + Kadane's

**Recurrence:** `Kadane's on compressed column sums`

### Time Complexity: O(N²×M) or O(M²×N)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(M)

**Example walkthrough:**
```
Fix cols l,r. Row sum = prefix[r]-prefix[l-1]. Kadane's on row sums.
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(M²×N²) | O(N) stack |
| Memoization | O(N²×M) or O(M²×N) | Same as tabulation |
| Tabulation | O(N²×M) or O(M²×N) | O(M) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
