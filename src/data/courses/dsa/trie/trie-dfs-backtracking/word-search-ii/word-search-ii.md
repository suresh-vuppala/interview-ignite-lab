Find all words from a dictionary that exist in a grid by traversing adjacent cells.

<br>

> board=[['o','a','a','n'],['e','t','a','e']], words=['oath','pea','eat','rain'] → ['oath','eat']
>
> **Key insight:** Build trie from words. DFS from each cell following trie paths. Prune dead branches.

<br>

---

## Constraints
- 1 ≤ M, N ≤ 12
- 1 ≤ words.length ≤ 3 × 10⁴
- 1 ≤ word.length ≤ 10

<br>

---

## All Possible Edge Cases
1. **No words found in board: empty result**
2. **All words found
3. **Duplicate words in input list
4. **Word longer than total cells**

<br>

---

## Solution 1: DFS per word separately

**Intuition:**
The most straightforward approach. Searching each word independently is slow — redundant grid traversal.

**Algorithm:**
1. Define recursive function with current state
2. At each step, try all possible choices
3. Recurse on remaining subproblem
4. Base case: return when subproblem is solved

### Time Complexity: O(W × M×N × 4^L)
**Why?**
Two factors multiply: one from iterating elements, one from the operation per element.
Total = product of both factors.

**Detailed breakdown:**
Depends on both dimensions of the input.

### Space Complexity: O(1) extra (or O(N) if using auxiliary structures)
**Why?**
Depends on whether auxiliary data structures are used. Pure brute force typically uses O(1) extra space beyond the input.

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
