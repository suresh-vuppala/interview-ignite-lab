Search words with wildcards: '.' matches any single character, '*' matches any sequence.

<br>

> Input:
> words = ["cat", "bat", "rat", "cart", "card"]
> search("c*t") → ["cat", "cart"]
> search(".at") → ["cat", "bat", "rat"]
> search("ca*d") → ["card"]

> Output:
> ["cat", "cart"], ["cat", "bat", "rat"], ["card"]

> Explanation:
> - "c*t": 'c' + any chars + 't' matches "cat", "cart"
> - ".at": any char + "at" matches "cat", "bat", "rat"
> - "ca*d": "ca" + any chars + "d" matches "card"
> 
> **Key insight:** Use DFS with backtracking to explore all matching paths.

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

## Solution: Trie with DFS and Backtracking

**Algorithm:**
1. Build trie with all words
2. DFS search with pattern:
   - **Regular char**: Follow that path only
   - **'.'**: Try all 26 children at current level
   - **'*'**: Try all possible lengths (0 to remaining)
3. Collect all words that match pattern

**Key insight:** '*' requires trying multiple path lengths, backtracking handles this.



<br>

### Time Complexity Analysis

**Build Trie: O(N×L)**
- Insert N words: O(N)
- Each word length L: O(L)

**Search with wildcards:**
- **'.' only**: O(26^W × L) where W = wildcards
- **'*' only**: O(N×L) worst case (match all words)
- **Mixed**: O(26^W × N×L) worst case

**Why so expensive?**
- Each '.' branches 26 ways
- Each '*' tries multiple lengths
- Combination creates exponential paths

**Space Complexity: O(N×L)**
- Trie storage: O(N×L)
- DFS recursion: O(L)
- Result storage: O(K) for K matches

**Optimization:**
- Early termination on impossible paths
- Cache pattern results
- Limit '*' expansion depth

**Applications:**
- File system search (*.txt)
- Regular expressions
- Database queries (LIKE operator)

> **Time Complexity:** O(N×L) build, O(26^W × N×L) search worst case
> **Space Complexity:** O(N×L)

<br>
<br>

---

---

```code```
