# Offline XOR Queries

## Problem Statement
Answer multiple queries for maximum XOR with elements up to index i.

## Approach

### Offline Processing
- Sort queries by index
- Build trie incrementally
- Answer queries as we add elements
- Time: O((N+Q)*32)

### Online with Persistent Trie
- Create version of trie at each index
- Answer queries using appropriate version
- Time: O(N*32), Query: O(32)

## Complexity
- Offline: O((N+Q)*32)
- Persistent: O(N*32) build, O(32) query

```code```
