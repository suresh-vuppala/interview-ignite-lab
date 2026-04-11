class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        # Extra Matrix: O(n²) space
        n = len(matrix)
        copy = [row[:] for row in matrix]
        for i in range(n):
            for j in range(n):
                matrix[j][n-1-i] = copy[i][j]