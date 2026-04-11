Given a grid of characters and a dictionary, find all words that can be formed in the grid by moving to adjacent cells (4 directions).

<br>

> Input:
> board = [["o","a","a","n"], ["e","t","a","e"], ["i","h","k","r"], ["i","f","l","v"]]
> words = ["oath", "pea", "eat", "rain"]

> Output:
> ["oath", "eat"]

> Explanation:
> Same as Word Search II - find words using 4-directional movement.
> 
> **Key insight:** Trie + DFS with backtracking in 4 directions.

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

## Solution: Trie + DFS (4 Directions)

Combine trie with DFS:
1. Build trie from dictionary
2. For each cell, start DFS
3. Explore 4 directions (up, down, left, right)
4. Mark visited, backtrack after exploring

**Key insight:** Same as Word Search II.

```code```

<br>

### Time Complexity Analysis

**Overall: O(M×N×4^L)**

**Build Trie: O(W×L)**
- W words, length L

**DFS Search: O(M×N×4^L)**
- M×N cells
- 4 directions per cell
- Max depth L

**Space Complexity: O(W×L + L)**
- Trie: O(W×L)
- Recursion: O(L)

> **Time Complexity:** O(M×N×4^L)
> **Space Complexity:** O(W×L)

<br>
<br>

---
