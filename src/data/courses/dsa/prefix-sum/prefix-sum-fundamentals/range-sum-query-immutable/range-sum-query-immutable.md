## Problem Statement

Given an integer array `nums`, implement the NumMatrix class:

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

### Naive Approach (Without Prefix Sum)
- For each query, iterate through the rectangle and sum all elements
- Time Complexity: O(m × n) per query, where m and n are the dimensions of the rectangle
- Space Complexity: O(1)

### Optimized Approach (With 2D Prefix Sum)
1. **Build Prefix Sum Matrix**: Create a 2D prefix sum array where `prefix[i][j]` represents the sum of all elements in the rectangle from `(0,0)` to `(i-1,j-1)`.

2. **Formula**:
   - `prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]`

3. **Query Calculation**: Use the inclusion-exclusion principle:
   - `sumRegion(row1, col1, row2, col2) = prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1]`

## Complexity Analysis

### Time Complexity
- **Initialization**: O(m × n) - We need to build the entire prefix sum array
- **Per Query**: O(1) - Each query is answered in constant time

### Space Complexity
- O(m × n) - For storing the prefix sum matrix

## Key Insights

- **2D Prefix Sum Pattern**: Similar to 1D prefix sum, but applied to 2D grids
- **Inclusion-Exclusion Principle**: When subtracting overlapping regions, we add back the corner that's subtracted twice
- **Trade-off**: We sacrifice space for time - O(m×n) space for O(1) queries

## Code Implementation

Below are the complete implementations of the NumMatrix class in different programming languages:

**Key Implementation Details:**
- Initialize the prefix array with dimensions (m+1) × (n+1) to handle boundary cases
- Build the prefix sum matrix using dynamic programming
- Answer queries in O(1) time using the precomputed prefix sums
- Handle edge cases at the boundaries of the matrix

Select a language above to view the implementation.

```code```
