Find if word exists in 2D grid by moving to adjacent cells (up, down, left, right). Same cell cannot be used twice.

<br>

> Input:
> board = [["A","B","C","E"],
>          ["S","F","C","S"],
>          ["A","D","E","E"]]
> word = "ABCCED"

> Output:
> true

> Explanation:
> Path: A(0,0) → B(0,1) → C(0,2) → C(1,2) → E(1,3) → D(2,3)
> 
> **Key insight:** DFS from each cell, mark visited, backtrack if path fails.

<br>

---

## Solution: Backtracking with DFS

**Intuition:**
Try starting from each cell in grid.
For each start, use DFS to explore all 4 directions.
Mark cells as visited to avoid reuse.
If word found, return true.
If stuck, backtrack by unmarking cell and trying different path.

**Algorithm:**
1. For each cell (i, j) in grid:
   - If board[i][j] == word[0], start DFS from this cell
2. DFS function:
   - Base case: if matched all characters, return true
   - Mark current cell as visited
   - Try all 4 directions (up, down, left, right):
     - Check if next cell valid and matches next character
     - If valid, recurse for next character
     - If recursion succeeds, return true
   - Unmark current cell (backtrack)
   - Return false if no direction works

**Example Walkthrough:**
```
board = [["A","B","C","E"],
         ["S","F","C","S"],
         ["A","D","E","E"]]
word = "ABCCED"

Try starting from (0,0)='A':
  Match 'A' ✓, search for 'B'
  Try up: out of bounds
  Try down: (1,0)='S' ≠ 'B'
  Try left: out of bounds
  Try right: (0,1)='B' ✓
    Match 'B' ✓, search for 'C'
    Mark (0,1) visited
    Try up: out of bounds
    Try down: (1,1)='F' ≠ 'C'
    Try left: (0,0)='A' visited
    Try right: (0,2)='C' ✓
      Match 'C' ✓, search for 'C'
      Mark (0,2) visited
      Try up: out of bounds
      Try down: (1,2)='C' ✓
        Match 'C' ✓, search for 'E'
        Mark (1,2) visited
        Try up: (0,2)='C' visited
        Try down: (2,2)='E' ✓
          Match 'E' ✓, search for 'D'
          Mark (2,2) visited
          Try up: (1,2)='C' visited
          Try down: out of bounds
          Try left: (2,1)='D' ✓
            Match 'D' ✓, all characters matched!
            Return true ✓

Path found: A(0,0) → B(0,1) → C(0,2) → C(1,2) → E(2,2) → D(2,1)
```

**Visual Path:**
```
Step 0:     Step 1:     Step 2:     Step 3:
A B C E     A→B C E     A→B→C E     A→B→C E
S F C S     S F C S     S F C S     S F ↓ S
A D E E     A D E E     A D E E     A D E E

Step 4:     Step 5:     Step 6:
A→B→C E     A→B→C E     A→B→C E
S F ↓ S     S F ↓ S     S F ↓ S
A D ↓ E     A←D ↓ E     A←D ↓ E (found!)
```

**Visited Tracking:**
```
Mark visited: board[i][j] = '#' (or use separate boolean array)
Unmark when backtracking: board[i][j] = original_char
```

### Time Complexity: O(N × M × 4^L)
**Why?**
- N × M cells to try as starting point
- For each start: DFS explores up to 4^L paths
- L = word length
- Each cell: 4 directions to try
- Total: O(N × M × 4^L)

**Detailed breakdown:**
- Starting points: N × M
- DFS from each start: 4 choices per level, L levels deep
- Worst case: 4^L paths explored per start
- Pruning reduces actual complexity significantly

### Space Complexity: O(L)
**Why?**
- Recursion stack: O(L) for word length
- Visited marking: O(1) if in-place, O(N×M) if separate array
- Total: O(L) with in-place marking

<br>

---

## Optimizations

**1. Early Termination:**
If word not found from any starting cell, return false immediately.

**2. Character Frequency Check:**
Before searching, check if board has all characters in word.
```cpp
if (count of any char in word > count in board) return false;
```

**3. Start from Rare Character:**
Find rarest character in word, start search from cells with that character.

**4. Bidirectional Search:**
Search from both ends of word simultaneously (advanced).

<br>

---

## Implementation Variations

**Approach 1: In-place Visited Marking**
```cpp
bool dfs(board, word, i, j, index) {
    if (index == word.length()) return true;
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (board[i][j] != word[index]) return false;
    
    char temp = board[i][j];
    board[i][j] = '#';  // Mark visited
    
    bool found = dfs(board, word, i+1, j, index+1) ||
                 dfs(board, word, i-1, j, index+1) ||
                 dfs(board, word, i, j+1, index+1) ||
                 dfs(board, word, i, j-1, index+1);
    
    board[i][j] = temp;  // Backtrack
    return found;
}
```

**Approach 2: Separate Visited Array**
```cpp
bool visited[m][n];

bool dfs(board, word, i, j, index, visited) {
    if (index == word.length()) return true;
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (visited[i][j] || board[i][j] != word[index]) return false;
    
    visited[i][j] = true;
    
    bool found = dfs(board, word, i+1, j, index+1, visited) ||
                 dfs(board, word, i-1, j, index+1, visited) ||
                 dfs(board, word, i, j+1, index+1, visited) ||
                 dfs(board, word, i, j-1, index+1, visited);
    
    visited[i][j] = false;  // Backtrack
    return found;
}
```

<br>

---

## Key Insights

1. **Try All Starts:** Word can start from any cell
2. **4 Directions:** Must explore up, down, left, right
3. **Visited Tracking:** Prevents using same cell twice
4. **Backtracking:** Unmark visited when path fails

**Common Mistakes:**
- Not unmarking visited cell when backtracking
- Not checking bounds before accessing board[i][j]
- Forgetting to check if cell already visited
- Not trying all possible starting cells

<br>

---

## Edge Cases

1. **Word not in board:** Return false
2. **Single cell board:** word="A", board=[["A"]] → true
3. **Word longer than board:** Impossible, return false
4. **Empty word:** Return true
5. **Word uses all cells:** Valid if path exists

<br>

---

## Comparison with Similar Problems

| Problem | Grid Type | Reuse Cells | Goal |
|---------|-----------|-------------|------|
| Word Search | 2D | No | Find one word |
| Word Search II | 2D | No | Find multiple words |
| Rat in Maze | 2D | No | Find all paths |
| N-Queens | 2D | No | Place N queens |

<br>

---

## Word Search II (Multiple Words)

**Problem:** Find all words from dictionary that exist in board.

**Approach:** Use Trie + DFS
1. Build Trie from dictionary words
2. DFS from each cell, traverse Trie simultaneously
3. When reach Trie leaf, word found

**Time:** O(N × M × 4^L) where L = max word length
**Space:** O(K × L) where K = number of words

<br>

---

## Applications

1. **Word Games:** Boggle, word search puzzles
2. **Pattern Matching:** Finding patterns in 2D data
3. **Image Processing:** Path finding in pixel grids
4. **Robotics:** Navigation in grid environments
5. **Bioinformatics:** Sequence matching in 2D structures

<br>
<br>

---

```code```
