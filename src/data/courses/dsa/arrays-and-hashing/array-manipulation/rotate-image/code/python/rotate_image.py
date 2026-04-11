# ============================================================
# Rotate Image (Matrix 90°)
# ============================================================

from typing import List

# ============================================================
# Solution 1: Use Extra Matrix
# Time: O(N²) | Space: O(N²)
# ============================================================
class Solution1:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        copy = [row[:] for row in matrix]

        for i in range(n):
            for j in range(n):
                matrix[j][n - 1 - i] = copy[i][j]

# ============================================================
# Solution 2: Transpose + Reverse Rows (Optimal)
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution2:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)

        # Step 1: Transpose
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        # Step 2: Reverse each row
        for row in matrix:
            row.reverse()
