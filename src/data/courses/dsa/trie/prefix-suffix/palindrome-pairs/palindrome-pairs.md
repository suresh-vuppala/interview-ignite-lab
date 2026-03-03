# Palindrome Pairs

## Problem Statement
Find all pairs of indices (i,j) where concatenation of words[i] + words[j] forms a palindrome.

## Approach

### Trie with Reverse
- Build trie with reversed words
- For each word:
  - Check if any trie path + word = palindrome
  - Check if word + any trie path = palindrome
- Time: O(N*L^2)

## Complexity
- Build: O(N*L)
- Search: O(N*L^2)
- Total: O(N*L^2)

```code```
