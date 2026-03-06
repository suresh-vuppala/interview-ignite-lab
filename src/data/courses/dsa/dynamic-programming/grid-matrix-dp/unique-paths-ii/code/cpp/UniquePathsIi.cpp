#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^(M+N)) | Space: O(M+N)
    int uniquePathsRecursive(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        return solveRecursive(m-1, n-1, obstacleGrid);
    }
    
    int solveRecursive(int i, int j, vector<vector<int>>& grid) {
        // Out of bounds or obstacle
        if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
        // Reached start
        if (i == 0 && j == 0) return 1;
        // Sum paths from top and left
        return solveRecursive(i-1, j, grid) + solveRecursive(i, j-1, grid);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int uniquePathsMemo(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solveMemo(m-1, n-1, obstacleGrid, memo);
    }
    
    int solveMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        // Return cached result
        if (memo[i][j] != -1) return memo[i][j];
        // Compute and cache
        memo[i][j] = solveMemo(i-1, j, grid, memo) + solveMemo(i, j-1, grid, memo);
        return memo[i][j];
    }
    
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int uniquePathsTab(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i > 0 || j > 0) {
                    int above = (i > 0) ? dp[i-1][j] : 0;
                    int left = (j > 0) ? dp[i][j-1] : 0;
                    dp[i][j] = above + left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED (TWO ROWS) ====================
    // Time: O(M×N) | Space: O(N)
    int uniquePathsTwoRows(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<int> prev(n, 0);
        prev[0] = 1;
        
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int above = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j-1] : 0;
                    curr[j] = above + left;
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
    
    // ==================== SOLUTION 5: SPACE OPTIMIZED (ONE ROW) - OPTIMAL ====================
    // Time: O(M×N) | Space: O(N)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    // dp[j] has value from previous row (above)
                    // dp[j-1] has updated value from current row (left)
                    dp[j] += dp[j-1];
                }
            }
        }
        
        return dp[n-1];
    }
};
