# Find Words in Grid

## Problem Statement
Given a grid of characters and a dictionary, find all words that can be formed in the grid.

## Approach

### Trie + DFS
- Build trie from dictionary
- For each cell:
  - Start DFS with trie traversal
  - Explore all valid directions
  - Collect complete words
- Avoid revisiting cells in same path

## Complexity
- Build: O(W*L)
- Search: O(M*N*D^L) where D=directions
- Space: O(W*L)

```code```
