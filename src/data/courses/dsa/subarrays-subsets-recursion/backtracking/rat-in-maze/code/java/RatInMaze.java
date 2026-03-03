import java.util.*;

class Solution {
    public List<String> findPath(int[][] maze) {
        List<String> result = new ArrayList<>();
        if (maze[0][0] == 0) return result;
        int n = maze.length;
        boolean[][] visited = new boolean[n][n];
        backtrack(maze, 0, 0, "", visited, result);
        return result;
    }
    
    void backtrack(int[][] maze, int i, int j, String path, boolean[][] visited, List<String> result) {
        int n = maze.length;
        if (i == n-1 && j == n-1) {
            result.add(path);
            return;
        }
        visited[i][j] = true;
        if (i+1 < n && maze[i+1][j] == 1 && !visited[i+1][j])
            backtrack(maze, i+1, j, path+"D", visited, result);
        if (j-1 >= 0 && maze[i][j-1] == 1 && !visited[i][j-1])
            backtrack(maze, i, j-1, path+"L", visited, result);
        if (j+1 < n && maze[i][j+1] == 1 && !visited[i][j+1])
            backtrack(maze, i, j+1, path+"R", visited, result);
        if (i-1 >= 0 && maze[i-1][j] == 1 && !visited[i-1][j])
            backtrack(maze, i-1, j, path+"U", visited, result);
        visited[i][j] = false;
    }
}