## Problem Statement
Count number of distinct substrings in a given string.

## Approach

### Trie-Based
- Insert all substrings into trie
- Count total nodes in trie
- Each node represents a distinct substring
- Time: O(N^2), Space: O(N^2)

### Optimization
- Use suffix array + LCP
- Time: O(N log N)

## Complexity
- Trie: O(N^2) time and space
- Suffix Array: O(N log N) time, O(N) space



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
