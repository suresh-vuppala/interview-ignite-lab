# Sum of Prefix Scores

## Problem Statement
For each word, calculate sum of scores of all its prefixes, where score is count of words having that prefix.

## Approach

### Trie with Prefix Count
- Build trie with prefix counts
- For each word:
  - Traverse and sum prefix counts
- Time: O(N*L)

## Complexity
- Build: O(N*L)
- Calculate: O(N*L)
- Total: O(N*L)

```code```
