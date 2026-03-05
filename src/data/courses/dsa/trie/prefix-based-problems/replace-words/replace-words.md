Replace words in sentence with their shortest root from dictionary.

<br>

> Input:
> dictionary = ["cat", "bat", "rat"]
> sentence = "the cattle was rattled by the battery"

> Output:
> "the cat was rat by the bat"

> Explanation:
> - "cattle" → "cat" (root found)
> - "rattled" → "rat" (root found)
> - "battery" → "bat" (root found)
> - Other words unchanged
> 
> **Key insight:** Trie finds shortest root by stopping at first isEnd flag.

<br>

---

## Solution: Trie with Early Termination

Use trie to find shortest roots:
1. Insert all dictionary roots into trie
2. For each word in sentence:
   - Traverse trie character by character
   - Stop at first root found (isEnd = true)
   - Replace word with root if found
3. Join words back into sentence

**Key insight:** First isEnd encountered = shortest root.

```code```

<br>

### Time Complexity Analysis

**Overall: O(D×L + S)**

**Build Trie: O(D×L)**
- Insert D dictionary words
- Each word average length L

**Process Sentence: O(S)**
- S = total characters in sentence
- Each character processed once
- Early termination at root

**Why Trie is efficient?**
- Finds shortest root in O(L) per word
- No need to check all dictionary words
- Alternative: HashSet O(D×L) per word

**Space Complexity: O(D×L)**
- Trie stores D dictionary words
- Shared prefixes reduce space

**Applications:**
- Text normalization
- Stemming algorithms
- Search query processing

> **Time Complexity:** O(D×L + S) for D roots and S sentence length
> **Space Complexity:** O(D×L) for trie storage

<br>
<br>

---
