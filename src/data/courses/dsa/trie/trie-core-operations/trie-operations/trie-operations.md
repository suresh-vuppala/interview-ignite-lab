## Problem Statement
Implement a Trie (prefix tree) data structure with the following operations:
- **Insert**: Add a word to the trie
- **Search**: Check if a word exists in the trie
- **StartsWith**: Check if any word starts with a given prefix
- **Delete**: Remove a word from the trie

## Approach

### Trie Node Structure
Each node contains:
- Array/Map of child nodes (26 for lowercase letters)
- Boolean flag to mark end of word

### Insert Operation
- Traverse character by character
- Create new nodes if path doesn't exist
- Mark last node as end of word
- Time: O(L), Space: O(L) where L = word length

### Search Operation
- Traverse character by character
- Return false if path breaks
- Check end-of-word flag at last node
- Time: O(L)

### StartsWith Operation
- Similar to search but don't check end flag
- Just verify path exists
- Time: O(L)

### Delete Operation
- Recursively delete nodes
- Remove node only if no other words use it
- Time: O(L)

## Complexity
- Insert: O(L) time, O(L) space
- Search: O(L) time, O(1) space
- StartsWith: O(L) time, O(1) space
- Delete: O(L) time, O(1) space

```code```
