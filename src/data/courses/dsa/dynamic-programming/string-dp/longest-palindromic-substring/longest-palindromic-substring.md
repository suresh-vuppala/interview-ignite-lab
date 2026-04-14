Find the longest palindromic substring.

<br>

> s='babad' → 'bab' or 'aba'
> **Key insight:** Expand around center: for each index (and each gap between indices), expand outward while palindrome. O(N²) time, O(1) space.

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

### Time Complexity: O(N³)
**Why?**
Three nested loops each running up to N iterations.
Total operations: N × N × N = N³.

**Detailed breakdown:**
For N=100: ~1 million operations. For N=1,000: ~1 billion — TLE.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Suboptimal time complexity for large inputs. Redundant work is performed.

> **Key Insight for Improvement:**
> Use a more efficient data structure or algorithm to reduce redundant computation.

<br>

---

## Solution 2: DP — Expand around center

**Recurrence:** `Expand from center`

### Time Complexity: O(N²)
**Why?** Each state computed once.

**Detailed breakdown:** States × transition cost

### Space Complexity: O(1)

**Example walkthrough:**
```
Center at 'a'(1): expand → 'bab'. Center at 'b'(2): expand → 'aba'. Max length=3.
```

<br>

---

## Complexity Progression Summary

| Solution | Time | Space |
|----------|------|-------|
| Recursion | O(N³) | O(N) stack |
| Memoization | O(N²) | Same as tabulation |
| Tabulation | O(N²) | O(1) |

**Key Insights:**
1. Identify recurrence and base cases
2. Optimize space if dp[i] depends only on previous row/state


<br><br>

---

```code```
