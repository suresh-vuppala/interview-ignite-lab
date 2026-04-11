class Solution {
    // Extra Matrix: O(n²) space
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int[][] copy = new int[n][n];
        for (int i = 0; i < n; i++) copy[i] = matrix[i].clone();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) matrix[j][n-1-i] = copy[i][j];
    }
}