Generate all subsets (power set) using recursion.

<br>

> Same as generate-all-subsequences — subsets ARE unordered subsequences
>
> **Key insight:** Include/exclude pattern. Same algorithm as subsequences.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Same

### Time Complexity: O(N×2^N)

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
