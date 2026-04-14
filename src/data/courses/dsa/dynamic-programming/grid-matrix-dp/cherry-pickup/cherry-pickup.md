Two people traverse grid from (0,0) to (n-1,n-1) and back. Collect maximum cherries. Equivalent to two simultaneous top-left to bottom-right paths.

<br>

> grid=[[0,1,-1],[1,0,-1],[1,1,1]] → 5
> **Key insight:** Model as two people walking simultaneously. dp[r1][c1][r2] where c2=r1+c1-r2. Both take k steps total, pick cherries (avoid double-counting same cell).

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

### Time Complexity: O(2^(2N))
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

## Solution 2: DP — 3D DP

**Recurrence:** `dp[r1][c1][r2] = grid[r1][c1] + grid[r2][c2] + max(4 transitions)`

### Time Complexity: O(N³)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(N³)

**Example walkthrough:**
```
Two simultaneous paths, 4 transition combinations per step
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(2^(2N)) | O(N) stack |
| Memoization | O(N³) | Same as tabulation |
| Tabulation | O(N³) | O(N³) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
