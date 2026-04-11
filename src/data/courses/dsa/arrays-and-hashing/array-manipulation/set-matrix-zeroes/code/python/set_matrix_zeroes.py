# ============================================================
# Set Matrix Zeroes
# ============================================================

from typing import List

# ============================================================
# Solution 1: Extra Sets
# Time: O(M×N) | Space: O(M+N)
# ============================================================
class Solution1:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        rows, cols = set(), set()
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    rows.add(i); cols.add(j)
        for i in range(m):
            for j in range(n):
                if i in rows or j in cols:
                    matrix[i][j] = 0

# ============================================================
# Solution 2: First Row/Column as Markers (Optimal)
# Time: O(M×N) | Space: O(1)
# ============================================================
class Solution2:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        first_row = any(matrix[0][j] == 0 for j in range(n))
        first_col = any(matrix[i][0] == 0 for i in range(m))

        # Mark using first row/col
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0

        # Zero based on markers
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # Handle first row/col
        if first_row: matrix[0] = [0] * n
        if first_col:
            for i in range(m): matrix[i][0] = 0
