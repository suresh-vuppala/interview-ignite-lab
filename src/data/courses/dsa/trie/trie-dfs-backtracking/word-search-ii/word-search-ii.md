## Problem Statement
Find all words from dictionary that exist in a 2D board. Words can be formed by sequentially adjacent cells.

## Approach

### Trie + DFS
- Build trie from dictionary
- For each cell:
  - Start DFS with trie root
  - Move to adjacent cells
  - Follow trie path
  - Add word when end node reached
- Time: O(M*N*4^L) where M*N=board size, L=max word length

### Optimization
- Remove found words from trie
- Prune dead branches
- Mark visited cells

## Complexity
- Build Trie: O(W*L) for W words
- DFS: O(M*N*4^L)
- Space: O(W*L)



---

## Constraints

- `1 ≤ number of words ≤ 3 × 10⁴`
- `1 ≤ word length ≤ 2000`
- `Words consist of lowercase English letters (unless stated otherwise)`

<br>

---

## All Possible Edge Cases

1. **Empty trie:** Search returns false, prefix returns false
2. **Single character words:** Trie depth = 1
3. **All same word inserted:** Count or flag must handle duplicates
4. **Prefix is also a complete word:** isEnd flag must be separate from having children
5. **Very long word:** Deep trie path
6. **No matching prefix:** Return false or empty list

<br>

---

```code```
