Find shortest unique prefix for each word that distinguishes it from all other words.

<br>

> Input:
> words = ["zebra", "dog", "duck", "dove"]

> Output:
> ["z", "dog", "du", "dov"]

> Explanation:
> - "zebra": "z" is unique (no other word starts with 'z')
> - "dog": "dog" needed ("do" shared with "dove" and "duck")
> - "duck": "du" is unique ("dove" has "dov")
> - "dove": "dov" is unique ("duck" has "duc")
> 
> **Key insight:** Unique prefix = first prefix with count = 1.

<br>


---

## Constraints

- `1 ≤ number of words ≤ 3 × 10⁴`
- `1 ≤ word length ≤ 2000`
- `Words consist of lowercase English letters (unless stated otherwise)`

<br>

---

## All Possible Edge Cases

1. **Empty trie:** Search returns false, prefix returns false
2. **Single character words:** Trie depth = 1
3. **All same word inserted:** Count or flag must handle duplicates
4. **Prefix is also a complete word:** isEnd flag must be separate from having children
5. **Very long word:** Deep trie path
6. **No matching prefix:** Return false or empty list

<br>

---

## Solution: Trie with Prefix Count

Use trie with prefix counting:
1. Build trie, increment prefixCount at each node
2. For each word:
   - Traverse trie character by character
   - Stop when prefixCount = 1 (unique prefix found)
   - Return prefix up to that point

**Key insight:** prefixCount = 1 means only this word uses this prefix.

```code```

<br>

### Time Complexity Analysis

**Overall: O(N×L)**

**Build Trie: O(N×L)**
- Insert N words
- Each word length L
- Increment prefixCount at each node

**Find Prefixes: O(N×L)**
- Traverse each word until prefixCount = 1
- Worst case: traverse entire word
- Total: N words × L length

**Why Trie is optimal?**
- Brute force: Compare each word with all others O(N²×L)
- Trie: Single pass O(N×L)
- Prefix counts maintained during insertion

**Space Complexity: O(N×L)**
- Trie stores N words
- Each node has prefixCount

**Applications:**
- Command-line completion
- Variable name suggestions
- DNS resolution

> **Time Complexity:** O(N×L) for N words of length L
> **Space Complexity:** O(N×L) for trie storage

<br>
<br>

---
