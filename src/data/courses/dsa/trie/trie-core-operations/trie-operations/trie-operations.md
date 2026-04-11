Implement a Trie (prefix tree) data structure with the following operations:
- **Insert**: Add a word to the trie
- **Search**: Check if a word exists in the trie
- **StartsWith**: Check if any word starts with a given prefix

<br>

> Input:
> Operations: ["insert", "apple"], ["search", "apple"], ["search", "app"], ["startsWith", "app"], ["insert", "app"], ["search", "app"]

> Output:
> [null, true, false, true, null, true]

> Explanation:
> - insert("apple"): Add "apple" to trie
> - search("apple"): Returns true (word exists)
> - search("app"): Returns false (prefix exists but not marked as word)
> - startsWith("app"): Returns true (prefix exists)
> - insert("app"): Add "app" to trie
> - search("app"): Returns true (now marked as word)
> 
> **Key insight:** Trie stores words character by character in tree structure.

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

## Solution: Trie Node with Children Array

**Trie Node Structure:**
- Array/Map of child nodes (26 for lowercase letters)
- Boolean flag to mark end of word

**Operations:**
1. **Insert**: Traverse character by character, create nodes if needed, mark end
2. **Search**: Traverse path, check end-of-word flag at last node
3. **StartsWith**: Traverse path, don't check end flag

**Key insight:** Each path from root to node represents a prefix.



<br>

### Time Complexity Analysis

**All Operations: O(L)** where L = word/prefix length

**Insert: O(L)**
- Traverse L characters: O(L)
- Create at most L new nodes: O(L)
- Mark end of word: O(1)

**Search: O(L)**
- Traverse L characters: O(L)
- Check end flag: O(1)

**StartsWith: O(L)**
- Traverse L characters: O(L)
- No end flag check needed

**Why Trie is efficient?**
- Prefix sharing: Common prefixes stored once
- Fast lookup: O(L) vs O(N×L) for array search
- Space-time tradeoff: Uses more space for faster queries

**Space Complexity: O(ALPHABET_SIZE × N × L)**
- N words, average length L
- Each node has ALPHABET_SIZE pointers (26 for lowercase)
- Shared prefixes reduce actual space

**Applications:**
- Autocomplete systems
- Spell checkers
- IP routing tables
- Dictionary implementations

> **Time Complexity:** O(L) for all operations
> **Space Complexity:** O(N×L) for N words of average length L

<br>
<br>

---

---

```code```
