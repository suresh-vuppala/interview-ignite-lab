## Problem Statement
Implement a compressed trie where chains of single-child nodes are merged into one edge.

## Approach

### Radix Tree Structure
- Each edge stores a string (not just char)
- Reduces space for long unique paths
- Split edges when branching occurs

### Operations
- **Insert**: Find longest matching prefix, split if needed
- **Search**: Match edge strings
- Time: O(L) but with fewer nodes

## Complexity
- Space: O(N) nodes instead of O(N*L)
- Operations: O(L) time

```code```
