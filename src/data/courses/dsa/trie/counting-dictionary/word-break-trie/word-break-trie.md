## Problem Statement
Determine if string can be segmented into words from dictionary.

## Approach

### Trie + DP
- Build trie from dictionary
- DP[i] = can segment s[0...i]
- For each position:
  - Traverse trie from current position
  - Mark reachable positions
- Time: O(N^2), Space: O(N)

## Complexity
- Build Trie: O(W*L)
- DP: O(N^2)
- Total: O(W*L + N^2)

```code```
