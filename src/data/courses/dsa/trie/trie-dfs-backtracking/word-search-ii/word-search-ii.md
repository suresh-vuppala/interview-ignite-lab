Find all words from a dictionary that exist in a grid by traversing adjacent cells.

<br>

> board=[['o','a','a','n'],['e','t','a','e']], words=['oath','pea','eat','rain'] → ['oath','eat']
>
> **Key insight:** Build trie from words. DFS from each cell following trie paths. Prune dead branches.

<br>

---

## Constraints
- Typical problem constraints

<br>

---

## Solution 1: DFS per word separately

### Time Complexity: O(W × M×N × 4^L)

> **Drawback:**
> Searching each word independently is slow — redundant grid traversal.

> **Key Insight for Improvement:**
> Single trie of all words + single grid DFS. Trie guides the search — only explore paths that match prefixes in the trie.

<br>

---

## Solution 2: Trie + Grid DFS (Optimal)

**Intuition:** Build trie from words. DFS from each cell following trie paths. Prune dead branches.

**Algorithm:**
1. Build trie from all words
2. For each cell (i,j): DFS with trie node
3. At each cell: if char matches trie child → continue DFS to neighbors
4. If isEnd → found word, add to result
5. Prune: remove trie branches with no remaining words

### Time Complexity: O(M×N × 4^L)
**Why?**
Each element/state processed efficiently.

**Detailed breakdown:**
Operations scale as described by the complexity.

**Example walkthrough:**
```
Start at 'o'→trie has 'oath'→DFS: o→a(right)→t(down)→h... found 'oath'
Start at 'e'→trie has 'eat'→e→a(up)→t(left)→found 'eat'
```

### Space Complexity: O(W×L)

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| DFS per word separately | O(W × M×N × 4^L) | Varies | Baseline |
| Trie + Grid DFS | O(M×N × 4^L) | O(W×L) | Optimal |

**Recommended Solution:** Trie + Grid DFS

**Key Insights:**
1. **Trie guides DFS:** Only explore paths matching dictionary prefixes
2. **Pruning:** Remove found words from trie to avoid duplicates and dead branches
3. **FAANG hard:** Combines trie + grid DFS + backtracking

<br><br>

---

```code```
