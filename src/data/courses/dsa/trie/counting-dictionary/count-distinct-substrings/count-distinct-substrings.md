## Problem Statement
Count number of distinct substrings in a given string.

## Approach

### Trie-Based
- Insert all substrings into trie
- Count total nodes in trie
- Each node represents a distinct substring
- Time: O(N^2), Space: O(N^2)

### Optimization
- Use suffix array + LCP
- Time: O(N log N)

## Complexity
- Trie: O(N^2) time and space
- Suffix Array: O(N log N) time, O(N) space

```code```
