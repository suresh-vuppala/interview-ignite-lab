Design structure for queries matching prefix AND suffix.

<br>

> Same as search-prefix-suffix — WordFilter design
>
> **Key insight:** Same suffix#word trie approach.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Scan all words per query

**Intuition:**
The most straightforward approach. Slow for repeated queries.

**Algorithm:**
1. Scan through each element from left to right
2. For each element, check the required condition
3. Track and return the best result

### Time Complexity: O(N×L) per query
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Slow for repeated queries.

> **Key Insight for Improvement:**
> Precompute suffix#word trie for O(L) queries.

<br>

---

## Solution 2: Suffix#Word Trie (Optimal)

**Intuition:** Same suffix#word trie approach.

**Algorithm:**
Same as search-prefix-suffix

### Time Complexity: O(N×L²) build, O(L) query
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same approach
```

### Space Complexity: O(N×L²)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Scan all words per query | O(N×L) per query | Varies | Baseline |
| Suffix#Word Trie | O(N×L²) build, O(L) query | O(N×L²) | Optimal |

**Recommended Solution:** Suffix#Word Trie

**Key Insights:**
1. **Same as search-prefix-suffix:** LeetCode 745 design problem

<br><br>

---

```code```
