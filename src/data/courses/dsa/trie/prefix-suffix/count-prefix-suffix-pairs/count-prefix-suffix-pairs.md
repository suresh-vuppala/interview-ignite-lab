## Problem Statement
Count pairs (i,j) where words[i] is both prefix and suffix of words[j].

## Approach

### Trie-Based
- Build trie with all words
- For each word:
  - Check if it's prefix of any word
  - Check if it's suffix of same word
- Time: O(N*L^2)

## Complexity
- Build: O(N*L)
- Count: O(N*L^2)
- Total: O(N*L^2)

```code```
