Find all dictionary words present in grid.

<br>

> Same as word-search-ii
>
> **Key insight:** Same trie + grid DFS approach.

<br>

---

## Constraints
- Same as word-search-ii

<br>

---

## Solution 1: Brute force per word

**Intuition:**
The most straightforward approach. Same redundancy.

**Algorithm:**
1. For each element i (outer loop):
   - For each element j (inner loop):
     - Check if the pair/condition is satisfied
2. Return the best result found

### Time Complexity: O(W×M×N×4^L)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

> **Drawback:**
> Same redundancy.

> **Key Insight for Improvement:**
> Same trie + DFS.

<br>

---

## Solution 2: Trie + Grid DFS (Optimal)

**Intuition:** Same trie + grid DFS approach.

**Algorithm:**
Same algorithm

### Time Complexity: O(M×N×4^L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same approach
```

### Space Complexity: O(W×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute force per word | O(W×M×N×4^L) | Varies | Baseline |
| Trie + Grid DFS | O(M×N×4^L) | O(W×L) | Optimal |

**Recommended Solution:** Trie + Grid DFS

**Key Insights:**
1. **Same family:** word-search-ii = boggle = find-words-grid

<br><br>

---

```code```
