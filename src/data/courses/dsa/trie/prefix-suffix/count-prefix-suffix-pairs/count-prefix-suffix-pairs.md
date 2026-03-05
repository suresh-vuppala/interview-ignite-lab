Count pairs (i,j) where i < j and words[i] is both a prefix and suffix of words[j].

<br>

> Input:
> words = ["a", "aba", "ababa", "aa"]

> Output:
> 4

> Explanation:
> Valid pairs:
> - (0,1): "a" is prefix and suffix of "aba"
> - (0,2): "a" is prefix and suffix of "ababa"
> - (0,3): "a" is prefix and suffix of "aa"
> - (1,2): "aba" is prefix and suffix of "ababa"
> 
> **Key insight:** Use trie to check prefix, then verify suffix condition.

<br>

---

## Solution: Trie with Suffix Verification

**Algorithm:**
1. Build trie with all words
2. For each word[i]:
   - Traverse trie to find all words with word[i] as prefix
   - For each candidate word[j]:
     - Check if word[i] is also suffix of word[j]
     - If yes and i < j, increment count
3. Return total count

**Key insight:** Trie finds prefix matches quickly, then verify suffix condition.

```code```

<br>

### Time Complexity Analysis

**Build Trie: O(N×L)**
- Insert N words: O(N)
- Each word length L: O(L)

**Count Pairs: O(N×L²)**
- For each word: O(N)
- Find prefix matches: O(L)
- Verify suffix for each match: O(L)
- Total: O(N×L²)

**Overall: O(N×L²)**

**Why Trie helps?**
- Brute force: O(N²×L) check all pairs
- Trie: O(N×L²) by pruning non-prefix pairs
- Prefix check: O(L) vs O(N×L)

**Space Complexity: O(N×L)**
- Trie storage: O(N×L)
- Temporary storage: O(1)

**Applications:**
- Pattern matching
- String analysis
- Text processing

> **Time Complexity:** O(N×L²)
> **Space Complexity:** O(N×L)

<br>
<br>

---
