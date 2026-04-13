Find all dictionary words present in grid.

<br>

> Same as word-search-ii
>
> **Key insight:** Same trie + grid DFS approach.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Brute force per word

### Time Complexity: O(W×M×N×4^L)

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
