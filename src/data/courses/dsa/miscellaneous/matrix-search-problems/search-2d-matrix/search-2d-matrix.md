Search for a target value in a 2D matrix where each row is sorted and first element of each row is greater than last element of previous row.

<br>

> Input:
> matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
> target = 3

> Output:
> true

> Explanation:
> Matrix is sorted row-wise and column-wise
> First element of each row > last element of previous row
> 
> **Key insight:** Treat 2D matrix as 1D sorted array and apply binary search.

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

## Solution 1: Linear Search

**Intuition:**
Check every element in the matrix.

**Algorithm:**
1. For each row:
   - For each column:
     - If matrix[i][j] == target, return true
2. Return false

**Example:**
```
matrix = [[1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]]
target = 3

Check: 1, 3 ✓ (found)
```

### Time Complexity: O(M × N)
**Why?**
- Visit each element once
- M rows, N columns
- Total: O(M × N)

### Space Complexity: O(1)
**Why?**
- Only loop variables
- No extra space

**Problem:** Too slow - doesn't use sorted property.

> **Key Insight for Improvement:**
> Matrix is fully sorted! Can we treat it as a 1D array and use binary search?

<br>

---

## Solution 2: Binary Search on Each Row

**Intuition:**
For each row, use binary search to find target.

**Algorithm:**
1. For each row:
   - Apply binary search on that row
   - If found, return true
2. Return false

**Example:**
```
matrix = [[1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]]
target = 3

Row 0: Binary search [1, 3, 5, 7]
  mid = 5, target < 5, search left
  mid = 1, target > 1, search right
  mid = 3, found ✓
```

### Time Complexity: O(M × log N)
**Why?**
- M rows
- Binary search per row: O(log N)
- Total: O(M × log N)

### Space Complexity: O(1)
**Why?**
- Only loop and binary search variables
- No extra space

**Improvement:** From O(M × N) to O(M × log N)

> **Key Insight for Improvement:**
> We're still checking all rows! Can we find the right row first, then search in it?

<br>

---

## Solution 3: Find Row, Then Binary Search

**Intuition:**
First find which row target could be in.
Then binary search in that row.

**Algorithm:**
1. Find row where target could exist:
   - Check if target >= matrix[i][0] and target <= matrix[i][N-1]
2. Binary search in that row

**Example:**
```
matrix = [[1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]]
target = 3

Find row:
  Row 0: 1 <= 3 <= 7 ✓ (target in this row)
  
Binary search in row 0: [1, 3, 5, 7]
  Found at index 1
```

### Time Complexity: O(M + log N)
**Why?**
- Find row: O(M)
- Binary search in row: O(log N)
- Total: O(M + log N)

### Space Complexity: O(1)
**Why?**
- Only variables
- No extra space

**Improvement:** From O(M × log N) to O(M + log N)

> **Key Insight for Improvement:**
> Can we use binary search to find the row too? Yes! Treat entire matrix as 1D array!

<br>

---

## Solution 4: Treat as 1D Array (Optimal)

**Intuition:**
Matrix is sorted like a 1D array.
Map 2D indices to 1D and apply binary search.

**Key Observation:**
```
Matrix:
[1,  3,  5,  7]   → indices 0, 1, 2, 3
[10, 11, 16, 20]  → indices 4, 5, 6, 7
[23, 30, 34, 60]  → indices 8, 9, 10, 11

As 1D array: [1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60]
```

**Mapping:**
```
1D index → 2D indices:
  row = index / N
  col = index % N

Example: index = 5
  row = 5 / 4 = 1
  col = 5 % 4 = 1
  matrix[1][1] = 11 ✓
```

**Algorithm:**
1. Set left = 0, right = M × N - 1
2. While left <= right:
   - mid = (left + right) / 2
   - row = mid / N, col = mid % N
   - If matrix[row][col] == target, return true
   - If matrix[row][col] < target, left = mid + 1
   - Else right = mid - 1
3. Return false

**Example Walkthrough:**
```
matrix = [[1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]]
target = 3

M = 3, N = 4
Total elements = 12

Step 1: left = 0, right = 11
  mid = 5
  row = 5 / 4 = 1, col = 5 % 4 = 1
  matrix[1][1] = 11
  11 > 3, right = 4

Step 2: left = 0, right = 4
  mid = 2
  row = 2 / 4 = 0, col = 2 % 4 = 2
  matrix[0][2] = 5
  5 > 3, right = 1

Step 3: left = 0, right = 1
  mid = 0
  row = 0 / 4 = 0, col = 0 % 4 = 0
  matrix[0][0] = 1
  1 < 3, left = 1

Step 4: left = 1, right = 1
  mid = 1
  row = 1 / 4 = 0, col = 1 % 4 = 1
  matrix[0][1] = 3
  3 == 3, found ✓
```

**Visual Representation:**
```
1D view: [1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60]
         0  1  2  3   4   5   6   7   8   9  10  11

Binary search for 3:
  mid = 5 (value 11) → too large, search left
  mid = 2 (value 5) → too large, search left
  mid = 0 (value 1) → too small, search right
  mid = 1 (value 3) → found ✓
```

### Time Complexity: O(log(M × N))
**Why?**
- Binary search on M × N elements
- Each step halves search space
- Total: O(log(M × N)) = O(log M + log N)

**Detailed breakdown:**
- Total elements: M × N
- Binary search: O(log(M × N))
- Index conversion: O(1)
- Total: O(log(M × N))

### Space Complexity: O(1)
**Why?**
- Only variables (left, right, mid, row, col)
- No extra space
- Total: O(1)

**Improvement:** From O(M + log N) to O(log(M × N))
- Example: M = 1000, N = 1000
- Previous: 1000 + log(1000) ≈ 1010 operations
- Optimal: log(1,000,000) ≈ 20 operations (50× faster!)

<br>

---

## Alternative: Staircase Search

**Intuition:**
Start from top-right corner.
Move left if current > target, down if current < target.

**Algorithm:**
1. Start at top-right: row = 0, col = N - 1
2. While in bounds:
   - If matrix[row][col] == target, return true
   - If matrix[row][col] > target, col-- (move left)
   - Else row++ (move down)
3. Return false

**Example:**
```
matrix = [[1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 60]]
target = 3

Start: (0, 3) = 7
  7 > 3, move left

Position: (0, 2) = 5
  5 > 3, move left

Position: (0, 1) = 3
  3 == 3, found ✓
```

**Why This Works:**
- At top-right: smallest in column, largest in row
- If current > target: all below are larger, move left
- If current < target: all left are smaller, move down

### Time Complexity: O(M + N)
**Why?**
- At most M + N moves
- Each move eliminates row or column
- Total: O(M + N)

### Space Complexity: O(1)
**Why?**
- Only row and col variables
- No extra space

**Note:** This works for matrices where rows and columns are sorted, but not necessarily the special property of this problem.

<br>

---

## Complexity Comparison

| Solution | Time | Space | Best For |
|----------|------|-------|----------|
| Linear Search | O(M × N) | O(1) | Small matrices |
| Binary per Row | O(M × log N) | O(1) | Few rows |
| Find Row + Binary | O(M + log N) | O(1) | Many columns |
| 1D Binary Search | O(log(M × N)) | O(1) | Optimal - this problem |
| Staircase Search | O(M + N) | O(1) | General sorted matrix |

<br>

---

## Edge Cases

1. **Empty matrix:** Return false
2. **Single element:** Check if equals target
3. **Target smaller than all:** Return false
4. **Target larger than all:** Return false
5. **Target in first row:** Works correctly
6. **Target in last row:** Works correctly

**Examples:**
```
matrix = [], target = 5 → false
matrix = [[5]], target = 5 → true
matrix = [[1, 2], [3, 4]], target = 0 → false
matrix = [[1, 2], [3, 4]], target = 5 → false
```

<br>

---

## Key Techniques

**1. Index Mapping (2D ↔ 1D):**
```cpp
// 1D to 2D
row = index / N
col = index % N

// 2D to 1D
index = row * N + col
```

**2. Binary Search Template:**
```cpp
left = 0, right = M * N - 1
while (left <= right):
    mid = (left + right) / 2
    // Convert to 2D
    row = mid / N
    col = mid % N
    // Compare and adjust
```

**3. Boundary Conditions:**
- Check matrix not empty
- Check M and N > 0
- Handle single row/column

<br>

---

## Common Mistakes

1. **Wrong index conversion:** Using row = mid % N (should be mid / N)
2. **Integer overflow:** mid = (left + right) / 2 can overflow
   - Fix: mid = left + (right - left) / 2
3. **Off-by-one errors:** right = M × N (should be M × N - 1)
4. **Not checking empty matrix:** Causes index out of bounds

<br>

---

## Applications

1. **Database Indexing:** Search in sorted 2D data structures
2. **Image Processing:** Find pixel values in sorted image matrices
3. **Spreadsheet Search:** Find values in sorted spreadsheets
4. **Game Development:** Search in sorted tile maps
5. **Scientific Computing:** Search in sorted data grids

<br>
<br>

---

```code```
