// ============================================================
// Spiral Matrix
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Simulation with Visited
// Time: O(M×N) | Space: O(M×N)
// ============================================================
class Solution1 {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        boolean[][] vis = new boolean[m][n];
        int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0, r = 0, c = 0;
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < m*n; i++) {
            result.add(matrix[r][c]); vis[r][c] = true;
            int nr = r+dirs[dir][0], nc = c+dirs[dir][1];
            if (nr<0||nr>=m||nc<0||nc>=n||vis[nr][nc]) { dir=(dir+1)%4; nr=r+dirs[dir][0]; nc=c+dirs[dir][1]; }
            r=nr; c=nc;
        }
        return result;
    }
}

// ============================================================
// Solution 2: Shrinking Boundaries (Optimal)
// Time: O(M×N) | Space: O(1) extra
// ============================================================
class Solution2 {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int top = 0, bot = matrix.length-1, left = 0, right = matrix[0].length-1;

        while (top <= bot && left <= right) {
            for (int j=left; j<=right; j++) result.add(matrix[top][j]); top++;
            for (int i=top; i<=bot; i++) result.add(matrix[i][right]); right--;
            if (top<=bot) { for (int j=right; j>=left; j--) result.add(matrix[bot][j]); bot--; }
            if (left<=right) { for (int i=bot; i>=top; i--) result.add(matrix[i][left]); left++; }
        }

        return result;
    }
}
