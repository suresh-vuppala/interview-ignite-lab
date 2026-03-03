## Problem Statement
Find the longest common prefix string amongst an array of strings.

**Example**: ["flower","flow","flight"] → "fl"

## Approach

### Method 1: Trie-Based
- Insert all words into trie
- Traverse trie until:
  - Node has multiple children, OR
  - Node marks end of word
- Time: O(N*L), Space: O(N*L)

### Method 2: Horizontal Scanning
- Compare first two strings
- Find their common prefix
- Compare result with next string
- Time: O(N*L), Space: O(1)

## Complexity
- Trie: O(N*L) time, O(N*L) space
- Scanning: O(N*L) time, O(1) space

```code```
