## Problem Statement
Design WordFilter class that supports queries with prefix and suffix, returning word with maximum weight.

## Approach

### Trie with All Combinations
- For word "apple":
  - Store: "e#apple", "le#apple", "ple#apple", etc.
- Query "ap" + "le":
  - Search for "le#ap"
- Time: O(L^2) per word

### Optimization
- Store only necessary combinations
- Use weight to prune

## Complexity
- Build: O(N*L^2)
- Query: O(L)
- Space: O(N*L^2)

```code```
