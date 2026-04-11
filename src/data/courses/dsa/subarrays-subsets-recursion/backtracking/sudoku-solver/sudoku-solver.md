Fill a 9×9 Sudoku board following the rules: each row, column, and 3×3 box must contain digits 1-9 exactly once.

<br>

> Input:
> board = [["5","3",".",".","7",".",".",".","."],
>          ["6",".",".","1","9","5",".",".","."],
>          [".","9","8",".",".",".",".","6","."],
>          ["8",".",".",".","6",".",".",".","3"],
>          ["4",".",".","8",".","3",".",".","1"],
>          ["7",".",".",".","2",".",".",".","6"],
>          [".","6",".",".",".",".","2","8","."],
>          [".",".",".","4","1","9",".",".","5"],
>          [".",".",".",".","8",".",".","7","9"]]

> Output:
> Filled board with all empty cells (.) replaced by valid digits

> Explanation:
> Each empty cell filled such that no conflicts in row, column, or 3×3 box
> 
> **Key insight:** Try digits 1-9 for each empty cell, check constraints, backtrack if invalid.

<br>


---

## Constraints

- `0 ≤ n ≤ 20 (for exponential solutions)`
- `n ≤ 10⁵ for polynomial solutions`
- `Values may include duplicates`

<br>

---

## All Possible Edge Cases

1. **Empty input:** Return [] or [[]]
2. **Single element:** One subset or one subarray
3. **All duplicates:** Must skip to avoid duplicate results
4. **n at maximum:** Verify 2ⁿ doesn't exceed time/memory limits
5. **Negative numbers:** Affects sum-based problems

<br>

---

## Solution: Backtracking with Constraint Checking

**Intuition:**
Find next empty cell, try placing digits 1-9.
For each digit, check if valid (no conflicts in row, column, box).
If valid, place digit and recurse to next empty cell.
If no valid digit works, backtrack and try different digit in previous cell.

**Sudoku Rules:**
1. Each row must contain 1-9 exactly once
2. Each column must contain 1-9 exactly once
3. Each 3×3 box must contain 1-9 exactly once

**Box Calculation:**
```cpp
For cell (row, col):
Box index = (row / 3) * 3 + (col / 3)

Box layout (9 boxes numbered 0-8):
0 1 2
3 4 5
6 7 8

Example: cell (4, 7)
Box = (4/3)*3 + (7/3) = 1*3 + 2 = 5
```

**Algorithm:**
1. Find next empty cell (value = '.')
2. If no empty cell, puzzle solved - return true
3. For digit 1 to 9:
   - Check if digit valid in current cell:
     - Not in same row
     - Not in same column
     - Not in same 3×3 box
   - If valid:
     - Place digit in cell
     - Recursively solve remaining puzzle
     - If recursion succeeds, return true
     - If recursion fails, remove digit (backtrack)
4. If no digit works, return false (trigger backtracking)

**Example Walkthrough (simplified 4×4):**
```
Initial:
. 2 | . .
. . | 3 .
----+----
. 3 | . 1
4 . | . .

Step 1: Try (0,0)
  Try 1: Check row 0, col 0, box 0 → valid
  Place 1:
  1 2 | . .
  . . | 3 .
  ----+----
  . 3 | . 1
  4 . | . .
  
  Step 2: Try (0,2)
    Try 1: Invalid (1 in box 0)
    Try 2: Invalid (2 in row 0)
    Try 3: Valid
    Place 3:
    1 2 | 3 .
    . . | 3 .  ← Wait, 3 appears twice in col 2!
    
    This leads to conflict later, backtrack...
    
  Try 3 at (0,0) instead:
  3 2 | . .
  . . | 3 .  ← 3 appears twice in col 2!
  
  Try 4 at (0,0):
  ... continue until solution found
```

**Constraint Checking:**
```cpp
bool isValid(board, row, col, digit) {
    // Check row
    for (int c = 0; c < 9; c++) {
        if (board[row][c] == digit) return false;
    }
    
    // Check column
    for (int r = 0; r < 9; r++) {
        if (board[r][col] == digit) return false;
    }
    
    // Check 3×3 box
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int r = boxRow; r < boxRow + 3; r++) {
        for (int c = boxCol; c < boxCol + 3; c++) {
            if (board[r][c] == digit) return false;
        }
    }
    
    return true;
}
```

### Time Complexity: O(9^(N×N))
**Why?**
- N = 9 for standard Sudoku
- Empty cells: up to 81
- Each empty cell: try 9 digits
- Worst case: 9^81 combinations
- Constraint checking prunes most branches
- Actual complexity much better due to pruning

**Detailed breakdown:**
- Theoretical worst: 9^81 ≈ 10^77
- Practical: Most puzzles solved in milliseconds
- Hard puzzles: May take seconds
- Constraint propagation reduces search space dramatically

### Space Complexity: O(N×N)
**Why?**
- Recursion stack: O(N×N) for 81 cells
- Board storage: O(N×N) = O(81) = O(1) for fixed size
- No additional data structures needed
- Total: O(N×N)

<br>

---

## Optimizations

**1. Choose Cell with Fewest Possibilities:**
Instead of finding first empty cell, find cell with minimum valid digits.
Reduces branching factor significantly.

**2. Constraint Propagation:**
Maintain sets of possible values for each cell.
Update sets when placing digits.
```cpp
// For each cell, track possible digits
set<int> possible[9][9];
```

**3. Naked Singles:**
If cell has only one possible digit, place it immediately.

**4. Hidden Singles:**
If digit can only go in one cell in row/col/box, place it.

**5. Precompute Constraints:**
Use boolean arrays for O(1) constraint checking:
```cpp
bool row[9][10];     // row[i][d] = digit d in row i
bool col[9][10];     // col[j][d] = digit d in col j
bool box[9][10];     // box[b][d] = digit d in box b
```

<br>

---

## Optimized Algorithm with Precomputed Constraints

**Time:** O(9^K) where K = empty cells (much faster)
**Space:** O(N×N)

```cpp
bool row[9][10], col[9][10], box[9][10];

bool solve(board) {
    // Find empty cell
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                int b = (i/3)*3 + (j/3);
                
                for (int d = 1; d <= 9; d++) {
                    if (!row[i][d] && !col[j][d] && !box[b][d]) {
                        board[i][j] = '0' + d;
                        row[i][d] = col[j][d] = box[b][d] = true;
                        
                        if (solve(board)) return true;
                        
                        board[i][j] = '.';
                        row[i][d] = col[j][d] = box[b][d] = false;
                    }
                }
                return false;
            }
        }
    }
    return true;  // All cells filled
}
```

<br>

---

## Key Insights

1. **Backtracking Core:** Try digit → Recurse → Undo if fails
2. **Three Constraints:** Row, column, and box must all be satisfied
3. **Early Pruning:** Check validity before recursing (huge speedup)
4. **Guaranteed Solution:** Valid Sudoku puzzles have unique solution

**Common Mistakes:**
- Wrong box calculation formula
- Not backtracking properly (not removing digit)
- Checking constraints after placing (should check before)
- Modifying input board without copying (if multiple solutions needed)

<br>

---

## Complexity Comparison

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(9^81) | O(1) | Try all combinations |
| Basic Backtracking | O(9^K) | O(N²) | K = empty cells |
| With Constraint Sets | O(9^K) | O(N²) | Faster constant |
| Dancing Links (DLX) | O(9^K) | O(N²) | Optimal for hard puzzles |

<br>

---

## Difficulty Levels

| Level | Empty Cells | Time | Techniques Needed |
|-------|-------------|------|-------------------|
| Easy | 30-40 | < 1ms | Basic backtracking |
| Medium | 40-50 | < 10ms | Some optimization |
| Hard | 50-60 | < 100ms | Constraint propagation |
| Expert | 60+ | < 1s | Advanced techniques |

<br>

---

## Applications

1. **Puzzle Games:** Sudoku solvers and generators
2. **Constraint Satisfaction:** General CSP solving
3. **Scheduling:** Resource allocation with constraints
4. **Logic Puzzles:** Similar constraint-based puzzles
5. **AI/ML:** Constraint learning and reasoning

<br>
<br>

---

```code```
