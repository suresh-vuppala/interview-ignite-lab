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

### Time Complexity: O(N³)

> **Drawback:** Overlapping subproblems cause exponential recomputation.

> **Key Insight for Improvement:** Memoize or tabulate. Recurrence: `Expand from center`

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
