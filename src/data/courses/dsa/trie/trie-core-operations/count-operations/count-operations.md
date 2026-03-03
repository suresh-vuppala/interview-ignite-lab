## Problem Statement
Extend Trie to support:
- **countWordsEqualTo**: Count how many times exact word exists
- **countWordsStartingWith**: Count words with given prefix

## Approach

### Modified Trie Node
Add two counters:
- `wordCount`: Number of times this word ends here
- `prefixCount`: Number of words passing through this node

### Count Words Equal To
- Traverse to end of word
- Return wordCount at that node
- Time: O(L)

### Count Words Starting With
- Traverse to end of prefix
- Return prefixCount at that node
- Time: O(L)

## Complexity
- Insert: O(L) time
- Count operations: O(L) time
- Space: O(N*L) for N words

```code```
