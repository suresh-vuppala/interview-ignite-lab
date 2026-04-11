// ============================================================
// Number of Provinces
// ============================================================
class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length, count = 0;
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++)
            if (!visited[i]) { count++; dfs(i, isConnected, visited); }
        return count;
    }
    void dfs(int city, int[][] mat, boolean[] visited) {
        visited[city] = true;
        for (int j = 0; j < mat.length; j++)
            if (mat[city][j] == 1 && !visited[j]) dfs(j, mat, visited);
    }
}
