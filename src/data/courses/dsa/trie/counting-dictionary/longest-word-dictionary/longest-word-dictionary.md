## Problem Statement
Find longest word that can be built one character at a time by other words in the array.

## Approach

### Trie + DFS
- Insert all words into trie
- DFS from root:
  - Only visit nodes that mark end of word
  - Track longest valid word
- Time: O(N*L)

## Complexity
- Build: O(N*L)
- DFS: O(N*L)
- Total: O(N*L)



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

```code```
