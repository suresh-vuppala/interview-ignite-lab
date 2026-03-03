# Dictionary with Wildcard Support

## Problem Statement
Implement dictionary that supports adding words and searching with '.' wildcard matching any character.

## Approach

### Trie + DFS for Wildcard
- Standard trie for storage
- Search with DFS:
  - On regular char: follow that path
  - On '.': try all 26 children
- Time: O(26^W * L) where W=wildcards

### Optimization
- Prune branches early
- Cache wildcard patterns

## Complexity
- Add: O(L)
- Search: O(26^W * L) worst case
- Space: O(N*L)

```code```
