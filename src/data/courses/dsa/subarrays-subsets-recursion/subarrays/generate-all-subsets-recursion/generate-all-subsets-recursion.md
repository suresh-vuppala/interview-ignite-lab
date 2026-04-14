Generate all subsets (power set) using recursion.

<br>

> Same as generate-all-subsequences — subsets ARE unordered subsequences
>
> **Key insight:** Include/exclude pattern. Same algorithm as subsequences.

<br>

---

## Constraints
- 0 ≤ N ≤ 20

<br>

---

## Solution 1: Same

**Intuition:**
The most straightforward approach. Can't avoid 2^N subsets.

**Algorithm:**
1. Iterate through all possible candidates/states
2. For each candidate, evaluate the required condition
3. Track the best result seen so far
4. Return the optimal answer

### Time Complexity: O(N×2^N)
**Why?**
Each element has multiple choices (include/exclude, take/skip), leading to exponential branching.
For N elements, the total states explored grow as 2^N or worse.

**Detailed breakdown:**
For N=20: ~1 million states. For N=30: ~1 billion states — too slow.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Can't avoid 2^N subsets.

> **Key Insight for Improvement:**
> Same include/exclude recursion.

<br>

---

## Solution 2: Backtracking (Optimal)

**Intuition:** Include/exclude pattern. Same algorithm as subsequences.

**Algorithm:**
Same as subsequences

### Time Complexity: O(N×2^N)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same as subsequences
```

### Space Complexity: O(N)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Same | O(N×2^N) | Varies | Baseline |
| Backtracking | O(N×2^N) | O(N) | Optimal |

**Recommended Solution:** Backtracking

**Key Insights:**
1. **Subsets = Power Set:** 2^N total
2. **Same algorithm as subsequences**
3. **Alternative:** Bitmask enumeration (iterative)

<br><br>

---

```code```
