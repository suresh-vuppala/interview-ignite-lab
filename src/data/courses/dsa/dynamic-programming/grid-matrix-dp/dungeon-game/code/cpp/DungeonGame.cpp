#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^(M+N)) | Space: O(M+N)
    int calculateMinimumHPRecursive(vector<vector<int>>& dungeon) {
        return solve(dungeon, 0, 0);
    }
    
private:
    int solve(vector<vector<int>>& dungeon, int i, int j) {
        int m = dungeon.size(), n = dungeon[0].size();
        if (i == m-1 && j == n-1) {
            return max(1, 1 - dungeon[i][j]);
        }
        if (i >= m || j >= n) return INT_MAX;
        int right = solve(dungeon, i, j+1);
        int down = solve(dungeon, i+1, j);
        int minHP = min(right, down) - dungeon[i][j];
        return max(1, minHP);
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int calculateMinimumHPMemo(vector<vector<int>>& dungeon) {
        unordered_map<string, int> memo;
        return solveMemo(dungeon, 0, 0, memo);
    }
    
private:
    int solveMemo(vector<vector<int>>& dungeon, int i, int j, unordered_map<string, int>& memo) {
        int m = dungeon.size(), n = dungeon[0].size();
        if (i == m-1 && j == n-1) {
            return max(1, 1 - dungeon[i][j]);
        }
        if (i >= m || j >= n) return INT_MAX;
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        int right = solveMemo(dungeon, i, j+1, memo);
        int down = solveMemo(dungeon, i+1, j, memo);
        int minHP = min(right, down) - dungeon[i][j];
        memo[key] = max(1, minHP);
        return memo[key];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int calculateMinimumHPTab(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m][n-1] = dp[m-1][n] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int minHP = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(1, minHP);
            }
        }
        return dp[0][0];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(M×N) | Space: O(N)
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n+1, INT_MAX);
        dp[n-1] = 1;
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int minHP = min(dp[j], dp[j+1]) - dungeon[i][j];
                dp[j] = max(1, minHP);
            }
        }
        return dp[0];
    }
};
