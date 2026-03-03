# Longest Word in Dictionary

## Problem Statement
Find longest word that can be built one character at a time by other words in the array.

## Approach

### Trie + DFS
- Insert all words into trie
- DFS from root:
  - Only visit nodes that mark end of word
  - Track longest valid word
- Time: O(N*L)

## Complexity
- Build: O(N*L)
- DFS: O(N*L)
- Total: O(N*L)

```code```
