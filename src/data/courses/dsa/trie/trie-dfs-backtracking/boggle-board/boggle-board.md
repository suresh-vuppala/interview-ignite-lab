Find all valid dictionary words in a Boggle board.

<br>

> Same as word-search-ii — trie + grid DFS
>
> **Key insight:** Same approach: trie of dictionary + DFS from each cell.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: Search each word separately

### Time Complexity: O(W×M×N×4^L)

> **Drawback:**
> Redundant traversals.

> **Key Insight for Improvement:**
> Trie + grid DFS — identical to word-search-ii.

<br>

---

## Solution 2: Trie + Grid DFS (Optimal)

**Intuition:** Same approach: trie of dictionary + DFS from each cell.

**Algorithm:**
Same as word-search-ii

### Time Complexity: O(M×N×4^L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Same as word-search-ii
```

### Space Complexity: O(W×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Search each word separately | O(W×M×N×4^L) | Varies | Baseline |
| Trie + Grid DFS | O(M×N×4^L) | O(W×L) | Optimal |

**Recommended Solution:** Trie + Grid DFS

**Key Insights:**
1. **Identical to word-search-ii:** Boggle = word search on grid
2. **Trie + DFS:** Standard approach for grid word finding

<br><br>

---

```code```
