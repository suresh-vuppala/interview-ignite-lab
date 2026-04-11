class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        # O(m*n) time, O(1) space — Use first row/col as markers
        m, n = len(matrix), len(matrix[0])
        first_row = any(matrix[0][j] == 0 for j in range(n))
        first_col = any(matrix[i][0] == 0 for i in range(m))
        
        # Mark zeros in first row/col
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        
        # Zero out based on markers
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        
        if first_row: matrix[0] = [0] * n
        if first_col:
            for i in range(m): matrix[i][0] = 0