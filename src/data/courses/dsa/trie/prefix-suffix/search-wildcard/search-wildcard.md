# Search with Wildcard

## Problem Statement
Search words with wildcards where '.' matches any character and '*' matches any sequence.

## Approach

### Trie + DFS
- Build trie with all words
- For search with wildcard:
  - DFS through trie
  - On '.': try all children
  - On '*': try all possible lengths
  - On letter: follow that path only
- Time: O(26^W) worst case, W=wildcards

## Complexity
- Build: O(N*L)
- Search: O(26^W * L)
- Space: O(N*L)

```code```
