Understand the difference between subarrays, subsequences, and subsets.

<br>

> arr=[1,2,3]: subarrays=[1],[2],[3],[1,2],[2,3],[1,2,3]; subsets=all combos; subsequences=ordered subsets
>
> **Key insight:** Subarrays: contiguous O(N²). Subsequences: maintain order, not contiguous O(2^N). Subsets: unordered O(2^N).

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: N/A — conceptual

### Time Complexity: N/A

> **Drawback:**
> N/A — foundational concept.

> **Key Insight for Improvement:**
> Subarrays ⊂ Subsequences. Subsets = unordered subsequences. Count: subarrays N(N+1)/2, subsets/subsequences 2^N.

<br>

---

## Solution 2: Conceptual Framework (Optimal)

**Intuition:** Subarrays: contiguous O(N²). Subsequences: maintain order, not contiguous O(2^N). Subsets: unordered O(2^N).

**Algorithm:**
Subarrays: nested loops i,j with i≤j → contiguous
Subsequences: include/exclude each element → ordered
Subsets: same as subsequences but order doesn't matter

### Time Complexity: Varies
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
arr=[1,2,3]: subarrays=6, subsequences=8, subsets=8
```

### Space Complexity: Varies

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| N/A — conceptual | N/A | Varies | Baseline |
| Conceptual Framework | Varies | Varies | Optimal |

**Recommended Solution:** Conceptual Framework

**Key Insights:**
1. **Subarrays ⊂ Subsequences:** Every subarray is a subsequence, not vice versa
2. **Subsets = Subsequences (unordered):** Same elements, order doesn't matter
3. **Key for interviews:** Knowing which type determines the algorithm

<br><br>

---

```code```
