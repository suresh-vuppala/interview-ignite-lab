# Replace Words

## Problem Statement
Replace words in sentence with their shortest root from dictionary.

**Example**: 
- Dictionary: ["cat","bat","rat"]
- Sentence: "the cattle was rattled by the battery"
- Output: "the cat was rat by the bat"

## Approach

### Trie-Based Solution
- Insert all roots into trie
- For each word in sentence:
  - Traverse trie character by character
  - Stop at first root found (shortest)
  - Replace word with root
- Time: O(D + S) where D=dictionary size, S=sentence length

## Complexity
- Build Trie: O(D*L)
- Process Sentence: O(S)
- Total: O(D*L + S)

```code```
