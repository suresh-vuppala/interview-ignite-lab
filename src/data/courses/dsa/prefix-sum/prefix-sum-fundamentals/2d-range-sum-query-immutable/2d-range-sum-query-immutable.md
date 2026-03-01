# 2D Range Sum Query - Immutable

## Problem Statement

Given a 2D matrix `matrix`, handle multiple queries of the following type:

Calculate the sum of the elements of `matrix` inside the rectangle defined by its upper left corner `(row1, col1)` and lower right corner `(row2, col2)`.

Implement the `NumMatrix` class:

- `NumMatrix(int[][] matrix)` - Initializes the object with the integer matrix `matrix`.
- `int sumRegion(int row1, int col1, int row2, int col2)` - Returns the sum of the elements of `matrix` inside the rectangle defined by its upper left corner `(row1, col1)` and lower right corner `(row2, col2)`.

You must design an algorithm that allows you to answer multiple queries efficiently.

### Example

```
NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8
numMatrix.sumRegion(1, 1, 2, 2); // return 11
numMatrix.sumRegion(1, 0, 2, 0); // return 8
```

## Approach

### Naive Approach
- For each query, iterate through the rectangle and sum all elements
- Time Complexity: O(m × n) per query
- Space Complexity: O(1)

### Optimized Approach (2D Prefix Sum)

1. **Build 2D Prefix Sum Matrix**:
   - Create a prefix array where `prefix[i][j]` = sum of all elements in rectangle from `(0,0)` to `(i-1, j-1)`

2. **Building Formula**:
   - `prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]`
   - The subtraction accounts for the overlap in the top and left regions

3. **Query Formula (Inclusion-Exclusion)**:
   - `sumRegion(r1, c1, r2, c2) = prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1]`

4. **Visual Example**:
   ```
   To get sum from (r1,c1) to (r2,c2):
   - Take the sum from (0,0) to (r2,c2): prefix[r2+1][c2+1]
   - Subtract the left rectangle: prefix[r2+1][c1]
   - Subtract the top rectangle: prefix[r1][c2+1]
   - Add back the corner: prefix[r1][c1] (was subtracted twice)
   ```

## Complexity Analysis

### Time Complexity
- **Initialization**: O(m × n) - Building the 2D prefix sum array
- **Per Query**: O(1) - Each query answered in constant time

### Space Complexity
- O(m × n) - For storing the prefix sum matrix

## Key Insights

- **2D Prefix Sum**: Extension of 1D prefix sum to 2D grids
- **Inclusion-Exclusion**: Essential for handling overlapping regions in 2D
- **Space-Time Trade-off**: O(m×n) space enables O(1) query time
- **Index Shifting**: Prefix array is (m+1) × (n+1) to handle boundary cases elegantly
- **Pattern Recognition**: Multiple overlapping rectangles need careful addition/subtraction logic

## Code Implementation

Below are the complete implementations of the NumMatrix class for 2D range queries:

**Key Implementation Details:**
- Create a 2D prefix sum array with dimensions (rows+1) × (cols+1)
- Use the 2D prefix formula: prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]
- Use inclusion-exclusion principle for query: answer = TL - L - T + corner
- Handle all boundary cases with the padded array dimensions

Select a language above to view the implementation.

```code```
