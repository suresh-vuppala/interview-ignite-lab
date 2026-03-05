Calculate sum of scores where score of a string is the number of non-empty prefixes that are also present in the array.

<br>

> Input:
> words = ["abc", "ab", "bc", "b"]

> Output:
> 5

> Explanation:
> - "abc": prefixes "a", "ab", "abc" → "ab" exists → score = 1
> - "ab": prefixes "a", "ab" → "ab" exists → score = 1
> - "bc": prefixes "b", "bc" → "b" exists → score = 1
> - "b": prefix "b" → "b" exists → score = 1
> - Total: 1 + 1 + 1 + 1 = 4 (actually sum of all prefix counts)
> 
> **Key insight:** Use prefix counts to calculate scores efficiently.

<br>

---

## Solution: Trie with Prefix Count

Use trie to count prefix occurrences:
1. Insert all words, increment prefixCount at each node
2. For each word:
   - Traverse trie and sum all prefixCounts along path
   - This gives total score for that word
3. Return sum of all scores

**Key insight:** prefixCount at each node = how many words share this prefix.

```code```

<br>

### Time Complexity Analysis

**Overall: O(N×L)**

**Build Trie: O(N×L)**
- Insert N words
- Each word length L
- Increment prefixCount at each character

**Calculate Scores: O(N×L)**
- Traverse each word: O(L)
- Sum prefix counts along path: O(L)
- Total: N × L

**Why Trie is efficient?**
- Brute force: Check each prefix against all words O(N²×L²)
- Trie: Prefix counts maintained during insertion O(N×L)
- Single traversal to calculate scores

**Space Complexity: O(N×L)**
- Trie stores N words
- Each node has prefixCount integer

**Applications:**
- Text analysis
- Search ranking
- Autocomplete scoring

> **Time Complexity:** O(N×L) for N words of length L
> **Space Complexity:** O(N×L) for trie storage

<br>
<br>

---
