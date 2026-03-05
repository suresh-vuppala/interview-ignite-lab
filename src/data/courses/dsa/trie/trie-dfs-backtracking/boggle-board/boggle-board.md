Find all valid words in a Boggle board using a dictionary. Words can be formed by moving to adjacent cells (8 directions).

<br>

> Input:
> board = [["o","a","a","n"], ["e","t","a","e"], ["i","h","k","r"], ["i","f","l","v"]]
> words = ["oath", "pea", "eat", "rain"]

> Output:
> ["oath", "eat"]

> Explanation:
> - "oath": o(0,0) → a(0,1) → t(1,1) → h(2,1) ✓
> - "eat": e(1,0) → a(0,1) → t(1,1) ✓
> - "pea", "rain": Cannot be formed
> 
> **Key insight:** Trie + DFS with 8-directional movement.

<br>

---

## Solution: Trie + DFS Backtracking

Combine trie with DFS:
1. Build trie from dictionary words
2. For each cell, start DFS in 8 directions
3. Mark visited cells, backtrack after exploring
4. Collect words when reaching end nodes

**Key insight:** Trie prunes invalid paths early.

```code```

<br>

### Time Complexity Analysis

**Overall: O(M×N×8^L)**

**Build Trie: O(W×L)**
- W words, each length L

**DFS Search: O(M×N×8^L)**
- M×N starting cells
- Each cell explores 8 directions
- Maximum depth L (word length)
- Trie pruning reduces actual complexity

**Space Complexity: O(W×L + M×N)**
- Trie: O(W×L)
- Recursion stack: O(L)
- Visited array: O(M×N)

> **Time Complexity:** O(M×N×8^L) with trie pruning
> **Space Complexity:** O(W×L + M×N)

<br>
<br>

---
