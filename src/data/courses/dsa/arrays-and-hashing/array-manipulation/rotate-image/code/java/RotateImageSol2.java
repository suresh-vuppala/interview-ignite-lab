class Solution {
    // Optimal: O(1) space — Transpose + reverse
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                int tmp = matrix[i][j]; matrix[i][j] = matrix[j][i]; matrix[j][i] = tmp;
            }
        for (int[] row : matrix) { int l=0, r=n-1; while(l<r) { int t=row[l]; row[l]=row[r]; row[r]=t; l++; r--; } }
    }
}