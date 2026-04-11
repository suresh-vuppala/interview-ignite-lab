Design a data structure to search words by both prefix and suffix.

<br>

> Input:
> words = ["apple", "application", "apply", "maple", "sample"]
> prefix = "app", suffix = "le"

> Output:
> ["apple", "application"]

> Explanation:
> Words starting with "app": ["apple", "application", "apply"]
> Words ending with "le": ["apple", "maple", "sample"]
> Intersection: ["apple", "application"]
> 
> Process:
> 1. Forward trie finds prefix matches
> 2. Reverse trie finds suffix matches
> 3. Return common word indices

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

## Solution: Two Tries with Index Intersection

Use two separate tries:
1. Forward trie for prefix matching
2. Reverse trie for suffix matching
3. Store word indices at end nodes
4. Intersect results from both tries

**Key insight:** Maintain two tries and intersect word indices for efficient dual-condition search.



<br>

### Time Complexity Analysis

**Build Phase: O(N * L)**
- Insert each word into forward trie: O(L)
- Insert reversed word into reverse trie: O(L)
- Total for N words: O(N * L)

**Query Phase: O(L + K)**
- Search prefix in forward trie: O(L)
- Search suffix in reverse trie: O(L)
- Intersect K matching indices: O(K)
- Total: O(L + K)

**Space Complexity: O(N * L)**
- Forward trie: O(N * L)
- Reverse trie: O(N * L)
- Total: O(N * L)

**Why Two Tries?**
- Single trie cannot efficiently match suffix
- Reverse trie converts suffix to prefix problem
- Index intersection ensures both conditions met

> **Time Complexity:** O(N * L) build, O(L + K) query
> **Space Complexity:** O(N * L) for two tries

<br>
<br>

---

---

```code```
