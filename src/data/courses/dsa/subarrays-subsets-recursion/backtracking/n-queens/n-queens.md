Place N queens on N×N chessboard such that no two queens attack each other.

<br>

> Input:
> n = 4

> Output:
> [[".Q..", "...Q", "Q...", "..Q."],
>  ["..Q.", "Q...", "...Q", ".Q.."]]

> Explanation:
> Two distinct solutions for 4-Queens problem
> Queens cannot attack each other (no two in same row, column, or diagonal)
> 
> **Key insight:** Place one queen per row, check column and diagonal conflicts before placing.

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
Place queens row by row (one queen per row guaranteed).
For each row, try placing queen in each column.
Check if placement is safe (no conflicts with previously placed queens).
If safe, place queen and recurse to next row.
If not safe or no solution found, backtrack.

**Constraints:**
A queen attacks:
1. Same row (handled by placing one queen per row)
2. Same column
3. Same diagonal (two types: / and \)

**Diagonal Formulas:**
```cpp
// For position (row, col):
Main diagonal (\): row - col = constant
Anti-diagonal (/): row + col = constant

Example on 4×4 board:
Main diagonals (\):
  row-col = -3: (0,3)
  row-col = -2: (0,2), (1,3)
  row-col = -1: (0,1), (1,2), (2,3)
  row-col =  0: (0,0), (1,1), (2,2), (3,3)
  row-col =  1: (1,0), (2,1), (3,2)
  row-col =  2: (2,0), (3,1)
  row-col =  3: (3,0)

Anti-diagonals (/):
  row+col = 0: (0,0)
  row+col = 1: (0,1), (1,0)
  row+col = 2: (0,2), (1,1), (2,0)
  row+col = 3: (0,3), (1,2), (2,1), (3,0)
  row+col = 4: (1,3), (2,2), (3,1)
  row+col = 5: (2,3), (3,2)
  row+col = 6: (3,3)
```

**Algorithm:**
1. Use three sets to track occupied columns and diagonals
2. For each row (0 to n-1):
   - Try placing queen in each column (0 to n-1)
   - Check if column, main diagonal, anti-diagonal are free
   - If safe:
     - Place queen, mark column and diagonals as occupied
     - Recurse to next row
     - If solution found, add to result
     - Backtrack: remove queen, unmark column and diagonals
3. Base case: all n queens placed (row == n)

**Example Walkthrough (n=4):**
```
Row 0: Try columns 0,1,2,3
  Place Q at (0,1): col=1, diag=−1, anti=1
  
  Row 1: Try columns 0,1,2,3
    Skip col=1 (occupied)
    Place Q at (1,3): col=3, diag=−2, anti=4
    
    Row 2: Try columns 0,1,2,3
      Place Q at (2,0): col=0, diag=2, anti=2
      
      Row 3: Try columns 0,1,2,3
        Skip col=0,1,3 (occupied)
        Place Q at (3,2): col=2, diag=1, anti=5
        
        All queens placed! Solution found:
        .Q..
        ...Q
        Q...
        ..Q.

Board visualization:
  0 1 2 3
0 . Q . .
1 . . . Q
2 Q . . .
3 . . Q .

Conflicts checked:
- Columns: {1, 3, 0, 2} - all different ✓
- Main diags: {-1, -2, 2, 1} - all different ✓
- Anti diags: {1, 4, 2, 5} - all different ✓
```

**Backtracking Tree (partial for n=4):**
```
                    Row 0
        /      |       |      \
      col0   col1    col2    col3
       |       |       |       |
     Row 1   Row 1   Row 1   Row 1
    / | \ \  / | \ \
   ...  ...  ...  ...
```

### Time Complexity: O(N!)
**Why?**
- Row 0: N choices
- Row 1: ≤ N-1 valid choices (some columns blocked)
- Row 2: ≤ N-2 valid choices
- ...
- Worst case: N × (N-1) × (N-2) × ... ≈ O(N!)
- Each solution: O(N²) to build board
- Total: O(N! × N²) but typically much less due to pruning

**Detailed breakdown:**
- Not all N! paths explored (many pruned early)
- Actual complexity closer to O(N!) due to constraint checking
- For n=8: ~92 solutions (not 8! = 40,320)

### Space Complexity: O(N)
**Why?**
- Recursion stack: O(N) for N rows
- Three sets (cols, diag, anti-diag): O(N) each
- Current board state: O(N²) but reused
- Total: O(N)

<br>

---

## Optimization: Bit Manipulation

**Intuition:**
Use integers as bitmasks instead of sets for faster operations.

**Approach:**
```cpp
void solve(row, cols, diag, anti_diag) {
    if (row == n) {
        add solution
        return
    }
    
    // available = positions not attacked
    available = ((1 << n) - 1) & ~(cols | diag | anti_diag)
    
    while (available) {
        col = rightmost set bit in available
        place queen at (row, col)
        
        solve(row+1, 
              cols | col,
              (diag | col) << 1,
              (anti_diag | col) >> 1)
        
        remove rightmost bit from available
    }
}
```

**Time:** O(N!) - same but faster constants
**Space:** O(N) - same but less memory

<br>

---

## Key Insights

1. **One Queen Per Row:** Simplifies problem - only choose column
2. **Diagonal Tracking:** row±col formulas identify diagonals uniquely
3. **Early Pruning:** Check constraints before recursing (huge speedup)
4. **Backtracking:** Remove queen and unmark constraints when backtracking

**Common Mistakes:**
- Forgetting to check both diagonal types
- Not backtracking properly (not unmarking constraints)
- Checking row conflicts (unnecessary if placing one per row)
- Wrong diagonal formulas

<br>

---

## Complexity Comparison

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(N^N) | O(N²) | Try all positions |
| Backtracking | O(N!) | O(N) | Prune invalid early |
| Bit Manipulation | O(N!) | O(N) | Faster constants |

<br>

---

## Solutions Count by N

| N | Solutions | Time (approx) |
|---|-----------|---------------|
| 1 | 1 | Instant |
| 4 | 2 | Instant |
| 8 | 92 | < 1ms |
| 10 | 724 | < 10ms |
| 12 | 14,200 | < 100ms |
| 15 | 2,279,184 | Few seconds |

<br>

---

## Applications

1. **Constraint Satisfaction:** Classic CSP problem
2. **Resource Allocation:** Non-conflicting resource placement
3. **Scheduling:** Tasks with mutual exclusion constraints
4. **Graph Coloring:** Related to independent set problem
5. **VLSI Design:** Component placement with interference constraints

<br>
<br>

---

```code```
