// Time: O(4^(N×M)), Space: O(N×M)

import java.util.*;

class Solution {
    public List<String> findPath(int[][] maze) {
        List<String> result = new ArrayList<>();
        int n = maze.length;
        if (n == 0 || maze[0][0] == 0 || maze[n-1][n-1] == 0) return result;
        
        boolean[][] visited = new boolean[n][n];
        backtrack(maze, 0, 0, n, "", visited, result);
        return result;
    }
    
    private void backtrack(int[][] maze, int i, int j, int n, String path, boolean[][] visited, List<String> result) {
        if (i == n-1 && j == n-1) {
            result.add(path);
            return;
        }
        
        visited[i][j] = true;
        
        if (i+1 < n && maze[i+1][j] == 1 && !visited[i+1][j]) backtrack(maze, i+1, j, n, path+"D", visited, result);
        if (j-1 >= 0 && maze[i][j-1] == 1 && !visited[i][j-1]) backtrack(maze, i, j-1, n, path+"L", visited, result);
        if (j+1 < n && maze[i][j+1] == 1 && !visited[i][j+1]) backtrack(maze, i, j+1, n, path+"R", visited, result);
        if (i-1 >= 0 && maze[i-1][j] == 1 && !visited[i-1][j]) backtrack(maze, i-1, j, n, path+"U", visited, result);
        
        visited[i][j] = false;
    }
}

public class RatInMaze {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] maze = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
        System.out.println(sol.findPath(maze));
    }
}
