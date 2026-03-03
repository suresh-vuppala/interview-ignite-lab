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

```code```
