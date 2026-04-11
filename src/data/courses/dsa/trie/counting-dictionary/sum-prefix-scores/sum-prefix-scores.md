## Problem Statement
For each word, calculate sum of scores of all its prefixes, where score is count of words having that prefix.

## Approach

### Trie with Prefix Count
- Build trie with prefix counts
- For each word:
  - Traverse and sum prefix counts
- Time: O(N*L)

## Complexity
- Build: O(N*L)
- Calculate: O(N*L)
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
