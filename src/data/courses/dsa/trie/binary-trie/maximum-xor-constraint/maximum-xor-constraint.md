## Problem Statement
Find maximum XOR of two elements where one element is ≤ K.

## Approach

### Binary Trie with Constraint
- Insert numbers into binary trie
- For query with constraint K:
  - Traverse trie respecting K's bits
  - Choose opposite bit when possible
  - Backtrack if constraint violated
- Time: O(N*32)

## Complexity
- Build: O(N*32)
- Query: O(32)
- Space: O(N*32)

```code```
