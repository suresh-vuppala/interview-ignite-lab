# Find Row with Maximum Number of 1s

Given a binary matrix (containing only 0s and 1s) where each row is sorted in non-decreasing order, find the row with the maximum number of 1s. Return the index of that row. If multiple rows have the same maximum count, return the smallest row index.

<br>

> Input:
> matrix = [
>   [0, 0, 0, 1],
>   [0, 1, 1, 1],
>   [1, 1, 1, 1],
>   [0, 0, 0, 0]
> ]

> Output:
> 2

> Explanation:
> Row 2 has the maximum number of 1s (4 ones).
> 
> **Key insight:** Since rows are sorted, all 1s appear at the end of each row. Finding the first 1 tells us the count.

<br>


---

## Constraints

- `Constraints vary by specific problem`
- `Check individual problem for exact bounds`

<br>

---

## All Possible Edge Cases

1. **Minimum input size:** Base case
2. **Maximum input size:** Performance boundary
3. **Edge values (0, INT_MAX, INT_MIN):** Boundary testing
4. **Empty or null input:** Handle gracefully

<br>

---

## Solution 1: Brute Force

**Intuition:**
Count the number of 1s in each row by summing all elements. Track the row with maximum count.

**Algorithm:**
1. Initialize maxCount = 0, maxRow = 0
2. For each row i:
   - Count number of 1s (sum of row)
   - If count > maxCount, update maxCount and maxRow
3. Return maxRow

### Time Complexity: O(M×N)
**Why?**
- Outer loop: M iterations (rows)
- Inner loop (sum): N iterations (columns)
- Each cell checked once: O(1) work
- Total: M × N × O(1) = O(M×N)

**Detailed breakdown:**
- For each of M rows, sum N elements
- Total operations: M × N
- Example: 100×100 matrix → 10,000 operations
- No early termination possible

### Space Complexity: O(1)
**Why?**
- Only variables: maxCount, maxRow, count
- No additional data structures
- Constant space regardless of input size

**Problem:** Doesn't utilize the sorted property of rows.

> **Key Insight for Improvement:**
> We're counting all elements even when we could stop early. If we find a row with N ones, we can stop immediately since that's the maximum possible.

<br>

---

## Solution 2: Brute Force with Early Termination

**Intuition:**
Same as brute force, but stop searching if we find a row with all 1s (count = N), since that's the maximum possible.

**Algorithm:**
1. Initialize maxCount = 0, maxRow = 0
2. For each row i:
   - Count number of 1s
   - If count > maxCount, update maxCount and maxRow
   - If maxCount == N, break (found maximum)
3. Return maxRow

### Time Complexity: O(M×N)
**Why worst case unchanged?**
- Worst case: no row has all 1s
- Must check all M rows completely
- Still O(M×N) in worst case

**Best case improvement:**
- Best case: first row has all 1s → O(N)
- Average case: depends on data distribution
- Early termination helps in practice

**Detailed breakdown:**
- If row k has all 1s: only check k rows → k×N operations
- If no row has all 1s: check all rows → M×N operations
- Example: If row 10 has all 1s in 1000×1000 matrix → 10×1000 = 10,000 operations (100× faster!)

### Space Complexity: O(1)
**Why?**
- Same as brute force
- Only constant space for variables

> **Key Insight for Improvement:**
> Since rows are sorted, all 1s are at the end. Instead of counting, we can binary search for the first 1. Count = N - firstIndex.

<br>

---

## Solution 3: Binary Search on Each Row

**Intuition:**
Since each row is sorted, use binary search to find the first occurrence of 1. The count of 1s = N - firstIndex.

**Algorithm:**
1. Initialize maxCount = 0, maxRow = 0
2. For each row i:
   - Binary search to find first index of 1
   - Calculate count = N - firstIndex (if 1 found)
   - If count > maxCount, update maxCount and maxRow
3. Return maxRow

### Time Complexity: O(M×log N)
**Why?**
- Outer loop: M iterations (rows)
- Binary search per row: O(log N)
- Total: M × log N

**Detailed breakdown:**
- Each row: binary search takes log N comparisons
- Total rows: M
- Total comparisons: M × log N
- Example: 1000×1000 matrix → 1000 × 10 = 10,000 operations

**Improvement:** From O(M×N) to O(M×log N)
- Example: 1000×1000 matrix
- Brute force: 1,000,000 operations
- Binary search: 10,000 operations (100× faster!)

### Space Complexity: O(1)
**Why?**
- Binary search uses constant space
- Only loop variables and pointers
- No recursion or additional structures

> **Key Insight for Improvement:**
> We're still checking all M rows independently. Can we use the fact that columns are also sorted? Yes! Use staircase approach to traverse the matrix efficiently.

<br>

---

## Solution 4: Staircase Traversal from Top-Right

**Intuition:**
Start from top-right corner. When we see a 1, move left to find more 1s in that row. When we see a 0, move down to next row. The last row where we moved left has the most 1s.

**Algorithm:**
1. Start at top-right: row = 0, col = N-1
2. Initialize maxRow = 0
3. While within bounds:
   - If matrix[row][col] == 1:
     - Update maxRow = row
     - Move left: col--
   - Else (matrix[row][col] == 0):
     - Move down: row++
4. Return maxRow

### Time Complexity: O(M+N)
**Why?**
- Maximum moves left: N (from rightmost to leftmost column)
- Maximum moves down: M (from top to bottom row)
- Each move eliminates either a column or row
- Total: at most M + N moves

**Detailed breakdown:**
- Start at (0, N-1)
- Each 1 encountered: move left (eliminate column)
- Each 0 encountered: move down (eliminate row)
- Maximum steps: M + N
- Example: 1000×1000 matrix → 2000 operations

**Improvement:** From O(M×log N) to O(M+N)
- Example: 1000×1000 matrix
- Binary search: 10,000 operations
- Staircase: 2000 operations (5× faster!)

### Space Complexity: O(1)
**Why?**
- Only two pointers: row and col
- One variable: maxRow
- Constant space

**Why this works:**
- When we see 1 at (row, col): all cells to the right are also 1 (row sorted)
- When we move left: we're counting more 1s in current row
- When we see 0: all cells to the left are also 0 (row sorted), move to next row
- The row where we moved left the most has the most 1s

> **Key Insight for Improvement:**
> Can we track the actual count while traversing? Yes! Keep track of how many times we moved left from each row to determine the exact count.

<br>

---

## Solution 5: Staircase with Count Tracking

**Intuition:**
Same as staircase but explicitly track the count of 1s for each row. The column position tells us how many 1s are in that row (count = N - col - 1).

**Algorithm:**
1. Start at top-right: row = 0, col = N-1
2. Initialize maxRow = 0, maxCount = 0
3. For each row:
   - While col >= 0 and matrix[row][col] == 1:
     - Move left: col--
   - Calculate count = N - col - 1
   - If count > maxCount:
     - Update maxCount = count
     - Update maxRow = row
   - Move to next row: row++
4. Return maxRow

### Time Complexity: O(M+N)
**Why?**
- Outer loop: M iterations (rows)
- Inner while loop: total N iterations across all rows
- Each column visited at most once
- Total: M + N

**Detailed breakdown:**
- Row iterations: M
- Column movements: at most N (col only decreases)
- Total: M + N
- Example: 1000×1000 matrix → 2000 operations

**Comparison with Solution 4:**
- Same time complexity: O(M+N)
- More explicit count tracking
- Easier to understand and verify

### Space Complexity: O(1)
**Why?**
- Variables: row, col, maxRow, maxCount
- No additional data structures
- Constant space

**Why this is optimal:**
- Must examine at least one element per row: Ω(M)
- Must potentially traverse entire top row: Ω(N)
- Lower bound: Ω(M+N)
- Our solution: O(M+N)
- Therefore, this is optimal!

<br>

---

## Complexity Progression Summary

| Solution | Time | Space | Key Improvement |
|----------|------|-------|----------------|
| Brute Force | O(M×N) | O(1) | Baseline - count all elements |
| Early Termination | O(M×N) | O(1) | Stop if all 1s found - best case O(N) |
| Binary Search | O(M×log N) | O(1) | Use row sorting - find first 1 |
| Staircase | O(M+N) | O(1) | Use both sortings - eliminate rows/cols |
| Staircase + Count | O(M+N) | O(1) | Explicit tracking - clearer logic |

**Key Insights:**
1. **Brute Force → Early Termination:** Stop when maximum found → best case improvement
2. **Early Termination → Binary Search:** Use row sorting → O(N) to O(log N) per row
3. **Binary Search → Staircase:** Use both sortings → eliminate binary search
4. **Staircase → Count Tracking:** Explicit count → clearer implementation

**When to use each:**
- **Brute Force:** Only for very small matrices
- **Binary Search:** When rows sorted but columns not
- **Staircase:** Optimal for row+column sorted binary matrices

> **Final Complexity:** O(M+N) time, O(1) space - Optimal!

<br>
<br>

---

```code```
