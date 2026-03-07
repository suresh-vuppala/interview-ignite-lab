#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^(M+N)) | Space: O(M+N)
    int minPathSumRecursive(vector<vector<int>>& grid) {
        return solve(grid, grid.size()-1, grid[0].size()-1);
    }
    
private:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;
        return grid[i][j] + min(solve(grid, i-1, j), solve(grid, i, j-1));
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int minPathSumMemo(vector<vector<int>>& grid) {
        unordered_map<string, int> memo;
        return solveMemo(grid, grid.size()-1, grid[0].size()-1, memo);
    }
    
private:
    int solveMemo(vector<vector<int>>& grid, int i, int j, unordered_map<string, int>& memo) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        memo[key] = grid[i][j] + min(solveMemo(grid, i-1, j, memo), solveMemo(grid, i, j-1, memo));
        return memo[key];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int minPathSumTab(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(M×N) | Space: O(N)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j-1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        return dp[n-1];
    }
};
