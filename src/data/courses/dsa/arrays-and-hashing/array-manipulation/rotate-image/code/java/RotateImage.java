class Solution {
    // O(n²) time, O(1) space — Transpose then reverse rows
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // Transpose
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int tmp = matrix[i][j]; matrix[i][j] = matrix[j][i]; matrix[j][i] = tmp;
            }
        // Reverse each row
        for (int[] row : matrix) {
            int l = 0, r = n - 1;
            while (l < r) { int tmp = row[l]; row[l] = row[r]; row[r] = tmp; l++; r--; }
        }
    }
}