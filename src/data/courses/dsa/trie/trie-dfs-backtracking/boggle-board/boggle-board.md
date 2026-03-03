# Boggle Board

## Problem Statement
Find all valid words in a Boggle board. Similar to Word Search II but with different movement rules.

## Approach

### Trie + DFS with Backtracking
- Build trie from dictionary
- For each cell as starting point:
  - DFS in all 8 directions
  - Track visited cells
  - Collect words at end nodes
- Time: O(M*N*8^L)

## Complexity
- Build Trie: O(W*L)
- Search: O(M*N*8^L)
- Space: O(W*L + M*N)

```code```
