Find all pairs (i,j) where i ≠ j and words[i] + words[j] forms a palindrome.

<br>

> Input:
> words = ["abcd", "dcba", "lls", "s", "sssll"]

> Output:
> [[0,1], [1,0], [3,2], [2,4]]

> Explanation:
> - words[0] + words[1] = "abcd" + "dcba" = "abcddcba" (palindrome)
> - words[1] + words[0] = "dcba" + "abcd" = "dcbaabcd" (palindrome)
> - words[3] + words[2] = "s" + "lls" = "slls" (palindrome)
> - words[2] + words[4] = "lls" + "sssll" = "llssssll" (palindrome)
> 
> **Key insight:** Use trie with reversed words to find matching pairs efficiently.

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

## Solution: Trie with Reversed Words

**Algorithm:**
1. Build trie with reversed words, store original indices
2. For each word, traverse trie:
   - **Case 1**: Word fully matches trie path, remaining trie part is palindrome
   - **Case 2**: Trie path fully consumed, remaining word part is palindrome
   - **Case 3**: Exact match with another word (check empty string)
3. Collect all valid pairs

**Key insight:** Reversing words converts suffix matching to prefix matching in trie.

```code```

<br>

### Time Complexity Analysis

**Build Trie: O(N×L)**
- Insert N words: O(N)
- Each word length L: O(L)
- Total: O(N×L)

**Find Pairs: O(N×L²)**
- For each word: O(N)
- Traverse trie: O(L)
- Check palindrome at each position: O(L)
- Total: O(N×L²)

**Overall: O(N×L²)**

**Why Trie is efficient?**
- Brute force: O(N²×L) check all pairs
- Trie approach: O(N×L²) by pruning impossible pairs
- Shared prefixes reduce comparisons

**Space Complexity: O(N×L)**
- Trie storage: O(N×L)
- Result pairs: O(N²) worst case

**Applications:**
- String matching problems
- Pattern recognition
- Text processing

> **Time Complexity:** O(N×L²)
> **Space Complexity:** O(N×L)

<br>
<br>

---
