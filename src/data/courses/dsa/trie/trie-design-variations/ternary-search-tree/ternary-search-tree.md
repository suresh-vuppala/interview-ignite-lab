## Problem Statement
Understand Ternary Search Tree (TST) - a space-efficient alternative to trie.

## Approach

### TST Structure
- Each node has 3 children:
  - Left: smaller character
  - Middle: equal character (continue word)
  - Right: larger character
- More space-efficient than standard trie
- Slower than trie but faster than BST

## Complexity
- Space: O(N) better than trie
- Search: O(L + log N)
- Insert: O(L + log N)

```code```
