## Problem Statement
Design data structure to search words by both prefix and suffix.

## Approach

### Two Tries
- Forward trie for prefix search
- Reverse trie for suffix search
- Intersect results from both
- Time: O(L) per search

### Combined Trie
- Store word indices at nodes
- Search prefix in forward trie
- Search suffix in reverse trie
- Find common indices

## Complexity
- Build: O(N*L)
- Query: O(L + K) where K=results
- Space: O(N*L)

```code```
