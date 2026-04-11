## Problem Statement
Determine if string can be segmented into words from dictionary.

## Approach

### Trie + DP
- Build trie from dictionary
- DP[i] = can segment s[0...i]
- For each position:
  - Traverse trie from current position
  - Mark reachable positions
- Time: O(N^2), Space: O(N)

## Complexity
- Build Trie: O(W*L)
- DP: O(N^2)
- Total: O(W*L + N^2)



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
