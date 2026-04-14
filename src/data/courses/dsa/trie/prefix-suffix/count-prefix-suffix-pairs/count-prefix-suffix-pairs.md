Count pairs (i,j) where word[i] is both prefix AND suffix of word[j].

<br>

> words=['a','aba','ababa'] → pairs where shorter is both prefix and suffix of longer
>
> **Key insight:** For each pair, check if words[i] is prefix AND suffix of words[j].

<br>

---

## Constraints
- 1 ≤ N ≤ 10⁵
- 1 ≤ word.length ≤ 10⁵

<br>

---

## Solution 1: Check all pairs naively

**Intuition:**
The most straightforward approach. Quadratic with length check.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(N²×L)
**Why?**
Two nested loops each running up to N iterations.
Outer loop: N iterations × Inner loop: up to N iterations = N² total operations.

**Detailed breakdown:**
For N=1,000: ~1 million operations (OK). For N=10,000: ~100 million (borderline TLE).

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Quadratic with length check.

> **Key Insight for Improvement:**
> Sort by length. For each word, check shorter words as prefix+suffix. Trie or Z-function can optimize.

<br>

---

## Solution 2: Optimized Pair Check (Optimal)

**Intuition:** For each pair, check if words[i] is prefix AND suffix of words[j].

**Algorithm:**
1. Sort words by length
2. For each pair (i,j) where len[i] ≤ len[j]:
   - Check if words[j].startsWith(words[i]) AND words[j].endsWith(words[i])

### Time Complexity: O(N²×L) or O(N×L) with trie
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
'a' is prefix and suffix of 'aba' → count 1
'a' is prefix and suffix of 'ababa' → count 2
```

### Space Complexity: O(N×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Check all pairs naively | O(N²×L) | Varies | Baseline |
| Optimized Pair Check | O(N²×L) or O(N×L) with trie | O(N×L) | Optimal |

**Recommended Solution:** Optimized Pair Check

**Key Insights:**
1. **Prefix + suffix check:** Two conditions must both hold
2. **KMP/Z-function:** Can find all prefix-suffix matches efficiently

<br><br>

---

```code```
