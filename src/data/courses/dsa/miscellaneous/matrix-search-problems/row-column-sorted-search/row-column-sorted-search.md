# Search in Row and Column Sorted Matrix

Given a matrix where each row is sorted in ascending order and each column is also sorted in ascending order, search for a target value. Return true if the target exists, false otherwise.

<br>

> Input:
> matrix = [
>   [1,  4,  7,  11],
>   [2,  5,  8,  12],
>   [3,  6,  9,  16],
>   [10, 13, 14, 17]
> ]
> target = 5

> Output:
> true

> Explanation:
> The value 5 exists at position (1,1).
> 
> **Key insight:** Rows and columns are independently sorted, but the last element of a row may be greater than the first element of the next row.

<br>

---

## Solution 1: Brute Force

**Intuition:**
Check every element in the matrix sequentially until we find the target or exhaust all elements.

**Algorithm:**
1. Iterate through each row
2. For each row, iterate through each column
3. If element equals target, return true
4. If no match found after checking all elements, return false

### Time Complexity: O(M×N)
**Why?**
- Outer loop: M iterations (rows)
- Inner loop: N iterations (columns)
- Each cell checked once: O(1) work per cell
- Total: M × N × O(1) = O(M×N)

**Detailed breakdown:**
- Worst case: target not in matrix or at last position
- Must check all M×N elements
- No early termination possible without using sorted property
- Example: 100×100 matrix → 10,000 comparisons

### Space Complexity: O(1)
**Why?**
- Only loop variables used
- No additional data structures
- Constant space regardless of input size

**Problem:** Doesn't utilize the sorted property of rows and columns.

> **Key Insight for Improvement:**
> Since each row is sorted, we can use binary search on individual rows instead of linear search, reducing time from O(N) to O(log N) per row.

<br>

---

## Solution 2: Binary Search on Each Row

**Intuition:**
Apply binary search on each row independently since rows are sorted. This reduces the search time per row from O(N) to O(log N).

**Algorithm:**
1. For each row in the matrix
2. Apply binary search to find target in that row
3. If found, return true
4. If not found in any row, return false

### Time Complexity: O(M×log N)
**Why?**
- Outer loop: M iterations (rows)
- Binary search per row: O(log N)
- Total: M × log N

**Detailed breakdown:**
- Each row: binary search takes log N comparisons
- Total rows: M
- Total comparisons: M × log N
- Example: 100×100 matrix → 100 × 7 ≈ 700 comparisons

**Improvement:** From O(M×N) to O(M×log N)
- Example: 1000×1000 matrix
- Brute force: 1,000,000 operations
- Binary search: 1,000 × 10 = 10,000 operations (100× faster!)

### Space Complexity: O(1)
**Why?**
- Binary search uses constant space
- Only loop variables and pointers
- No recursion or additional structures

> **Key Insight for Improvement:**
> We're still checking all M rows. Can we eliminate some rows? Yes! If target is outside a row's range [row[0], row[N-1]], skip that row entirely.

<br>

---

## Solution 3: Row Elimination + Binary Search

**Intuition:**
Before applying binary search on a row, check if target falls within that row's range. Skip rows where target < row[0] or target > row[N-1].

**Algorithm:**
1. For each row in the matrix
2. Check if row[0] ≤ target ≤ row[N-1]
3. If yes, apply binary search on that row
4. If found, return true
5. If no valid row found, return false

### Time Complexity: O(M + log N)
**Why?**
- Row range checks: O(M) - check all rows
- Binary search: O(log N) - only on one valid row
- Total: O(M + log N)

**Detailed breakdown:**
- Checking M rows: M comparisons
- Binary search on one row: log N comparisons
- Total: M + log N
- Example: 1000×1000 matrix → 1000 + 10 = 1010 operations

**Improvement:** From O(M×log N) to O(M + log N)
- Eliminates binary search on invalid rows
- Best case: O(M) if target not in any row's range
- Worst case: O(M + log N) if target in last row

### Space Complexity: O(1)
**Why?**
- Same as previous solution
- Only constant space for variables

> **Key Insight for Improvement:**
> We're still doing O(M) work to check rows. Can we use both row AND column sorting together? Yes! Start from a corner where we can make decisions based on comparisons.

<br>

---

## Solution 4: Staircase Search from Top-Right

**Intuition:**
Start from top-right corner. At any position (i,j):
- If matrix[i][j] > target: move left (smaller values in same row)
- If matrix[i][j] < target: move down (larger values in same column)
- If matrix[i][j] == target: found!

This works because:
- Moving left decreases value (row sorted ascending)
- Moving down increases value (column sorted ascending)

**Algorithm:**
1. Start at top-right: row = 0, col = N-1
2. While within bounds:
   - If matrix[row][col] == target, return true
   - If matrix[row][col] > target, move left (col--)
   - If matrix[row][col] < target, move down (row++)
3. Return false if bounds exceeded

### Time Complexity: O(M+N)
**Why?**
- Maximum moves left: N (from rightmost to leftmost column)
- Maximum moves down: M (from top to bottom row)
- Each comparison eliminates either a row or column
- Total: at most M + N moves

**Detailed breakdown:**
- Start at (0, N-1)
- Worst path: traverse entire top row + entire left column
- Maximum steps: N + M
- Example: 1000×1000 matrix → 1000 + 1000 = 2000 operations

**Improvement:** From O(M + log N) to O(M+N)
- No binary search needed
- Linear in dimensions, not area
- Example: 1000×1000 matrix
  - Previous: 1000 + 10 = 1010 operations
  - Current: 1000 + 1000 = 2000 operations
  - (Slightly slower but simpler, no binary search)

### Space Complexity: O(1)
**Why?**
- Only two pointers: row and col
- No additional data structures
- Constant space

**Why this works:**
- At each step, we eliminate either an entire row or column
- If current > target: all elements below are larger (column sorted)
- If current < target: all elements to left are smaller (row sorted)
- This guarantees we don't miss the target

> **Key Insight for Improvement:**
> Can we start from a different corner? Yes! Bottom-left works with similar logic. Top-left and bottom-right don't work (ambiguous direction).

<br>

---

## Solution 5: Staircase Search from Bottom-Left

**Intuition:**
Start from bottom-left corner. At any position (i,j):
- If matrix[i][j] > target: move up (smaller values in same column)
- If matrix[i][j] < target: move right (larger values in same row)
- If matrix[i][j] == target: found!

**Algorithm:**
1. Start at bottom-left: row = M-1, col = 0
2. While within bounds:
   - If matrix[row][col] == target, return true
   - If matrix[row][col] > target, move up (row--)
   - If matrix[row][col] < target, move right (col++)
3. Return false if bounds exceeded

### Time Complexity: O(M+N)
**Why?**
- Same as top-right approach
- Maximum moves up: M
- Maximum moves right: N
- Total: M + N

**Detailed breakdown:**
- Start at (M-1, 0)
- Worst path: traverse entire bottom row + entire right column
- Maximum steps: M + N
- Identical complexity to Solution 4

### Space Complexity: O(1)
**Why?**
- Only two pointers
- No additional structures
- Constant space

**Comparison with Top-Right:**
- Same time complexity: O(M+N)
- Same space complexity: O(1)
- Choice is personal preference
- Both eliminate rows/columns efficiently

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(M×N) | O(1) | Baseline - checks all elements |
| Binary Search Each Row | O(M×log N) | O(1) | Use row sorting - binary search |
| Row Elimination | O(M + log N) | O(1) | Skip invalid rows - range check |
| Staircase Top-Right | O(M+N) | O(1) | Use both sortings - eliminate row/col |
| Staircase Bottom-Left | O(M+N) | O(1) | Alternative corner - same efficiency |

**Key Insights:**
1. **Brute Force → Binary Search:** Use row sorting → O(N) to O(log N) per row
2. **Binary Search → Row Elimination:** Skip invalid rows → reduce to one binary search
3. **Row Elimination → Staircase:** Use both sortings → eliminate binary search entirely
4. **Top-Right → Bottom-Left:** Alternative starting point → same complexity

**When to use each:**
- **Brute Force:** Only when matrix is very small or unsorted
- **Binary Search:** When rows sorted but columns not
- **Staircase:** Optimal for row+column sorted matrices

> **Final Complexity:** O(M+N) time, O(1) space

<br>
<br>

---

```code```
