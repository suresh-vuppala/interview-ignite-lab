// ============================================================
// Set Matrix Zeroes
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Extra Sets
// Time: O(M×N) | Space: O(M+N)
// ============================================================
class Solution1 {
    public void setZeroes(int[][] matrix) {
        Set<Integer> rows = new HashSet<>(), cols = new HashSet<>();
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[0].length; j++)
                if (matrix[i][j] == 0) { rows.add(i); cols.add(j); }
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[0].length; j++)
                if (rows.contains(i) || cols.contains(j)) matrix[i][j] = 0;
    }
}

// ============================================================
// Solution 2: First Row/Column as Markers (Optimal)
// Time: O(M×N) | Space: O(1)
// ============================================================
class Solution2 {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean fr = false, fc = false;
        for (int j = 0; j < n; j++) if (matrix[0][j] == 0) fr = true;
        for (int i = 0; i < m; i++) if (matrix[i][0] == 0) fc = true;
        for (int i = 1; i < m; i++) for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0) { matrix[i][0] = 0; matrix[0][j] = 0; }
        for (int i = 1; i < m; i++) for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        if (fr) Arrays.fill(matrix[0], 0);
        if (fc) for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
}
