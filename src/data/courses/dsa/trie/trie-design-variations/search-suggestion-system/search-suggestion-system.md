## Problem Statement
Design a system that suggests products after each character typed, returning top 3 lexicographically.

## Approach

### Trie + DFS
- Build trie with all products
- For each prefix:
  - Traverse to prefix node
  - DFS to collect words
  - Sort and return top 3
- Time: O(L + K log K) where K=matching words

### Optimization
- Pre-sort at each node
- Store only top 3
- Query becomes O(L)

## Complexity
- Build: O(N*L*log N)
- Query: O(L)
- Space: O(N*L)

```code```
