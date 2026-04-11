// ============================================================
// Rotate Image (Matrix 90°)
// ============================================================

// ============================================================
// Solution 1: Use Extra Matrix
// Time: O(N²) | Space: O(N²)
// ============================================================
class Solution1 {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int[][] copy = new int[n][n];
        for (int i = 0; i < n; i++) copy[i] = matrix[i].clone();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[j][n - 1 - i] = copy[i][j];
    }
}

// ============================================================
// Solution 2: Transpose + Reverse Rows (Optimal)
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution2 {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        // Transpose
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }

        // Reverse each row
        for (int[] row : matrix) {
            int l = 0, r = n - 1;
            while (l < r) { int t = row[l]; row[l] = row[r]; row[r] = t; l++; r--; }
        }
    }
}
