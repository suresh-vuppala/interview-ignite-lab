Find the longest common prefix string amongst an array of strings.

<br>

> Input:
> strs = ["flower", "flow", "flight"]

> Output:
> "fl"

> Explanation:
> - "flower" and "flow" share "flow"
> - "flow" and "flight" share "fl"
> - Longest common prefix: "fl"
> 
> **Key insight:** Trie helps find common prefix by traversing until branching occurs.

<br>

> Input:
> strs = ["dog", "racecar", "car"]

> Output:
> ""

> Explanation:
> No common prefix exists among the strings.

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

## Solution: Trie Traversal

Use trie to find longest common prefix:
1. Insert all words into trie
2. Traverse from root until:
   - Node has multiple children (branching), OR
   - Node marks end of word (one word is prefix of another)
3. Path traversed is the longest common prefix

**Key insight:** Common prefix = path before first branch or word end.



<br>

### Time Complexity Analysis

**Overall: O(N×L)**

**Insert Phase: O(N×L)**
- Insert N words: O(N)
- Each word length L: O(L)
- Total: O(N×L)

**Traverse Phase: O(L)**
- Traverse at most L characters
- Stop at first branch or word end

**Why Trie approach?**
- Visualizes common structure
- Efficient for multiple queries
- Alternative: Horizontal scanning O(N×L) with O(1) space

**Space Complexity: O(N×L)**
- Trie stores all N words
- Each word length L
- Shared prefixes reduce actual space

**Applications:**
- Autocomplete systems
- File path matching
- DNA sequence analysis

> **Time Complexity:** O(N×L) for N words of length L
> **Space Complexity:** O(N×L) for trie storage

<br>
<br>

---

---

```code```
