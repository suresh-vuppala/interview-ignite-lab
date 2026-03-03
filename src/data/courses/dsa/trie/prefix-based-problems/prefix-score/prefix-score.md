## Problem Statement
Calculate sum of scores where score of a string is the number of non-empty prefixes that are also present in the array.

## Approach

### Trie with Prefix Count
- Insert all words with prefix counting
- For each word:
  - Traverse and sum all prefix counts
- Time: O(N*L)

## Complexity
- Build Trie: O(N*L)
- Calculate scores: O(N*L)
- Total: O(N*L)

```code```
