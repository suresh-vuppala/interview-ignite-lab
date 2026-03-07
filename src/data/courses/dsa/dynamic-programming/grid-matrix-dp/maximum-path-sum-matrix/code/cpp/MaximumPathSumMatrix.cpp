#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(3^M) | Space: O(M)
    int maxPathSumRecursive(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int result = INT_MIN;
        for (int j = 0; j < n; j++) {
            result = max(result, solve(matrix, m-1, j));
        }
        return result;
    }
    
private:
    int solve(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix[0].size();
        if (j < 0 || j >= n) return INT_MIN;
        if (i == 0) return matrix[0][j];
        return matrix[i][j] + max({solve(matrix, i-1, j-1), solve(matrix, i-1, j), solve(matrix, i-1, j+1)});
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int maxPathSumMemo(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<string, int> memo;
        int result = INT_MIN;
        for (int j = 0; j < n; j++) {
            result = max(result, solveMemo(matrix, m-1, j, memo));
        }
        return result;
    }
    
private:
    int solveMemo(vector<vector<int>>& matrix, int i, int j, unordered_map<string, int>& memo) {
        int n = matrix[0].size();
        if (j < 0 || j >= n) return INT_MIN;
        if (i == 0) return matrix[0][j];
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        memo[key] = matrix[i][j] + max({solveMemo(matrix, i-1, j-1, memo), 
                                        solveMemo(matrix, i-1, j, memo), 
                                        solveMemo(matrix, i-1, j+1, memo)});
        return memo[key];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(M×N) | Space: O(M×N)
    int maxPathSumTab(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int leftDiag = (j > 0) ? dp[i-1][j-1] : INT_MIN;
                int rightDiag = (j < n-1) ? dp[i-1][j+1] : INT_MIN;
                dp[i][j] = matrix[i][j] + max({up, leftDiag, rightDiag});
            }
        }
        return *max_element(dp[m-1].begin(), dp[m-1].end());
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(M×N) | Space: O(N)
    int maxPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev = matrix[0];
        for (int i = 1; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int up = prev[j];
                int leftDiag = (j > 0) ? prev[j-1] : INT_MIN;
                int rightDiag = (j < n-1) ? prev[j+1] : INT_MIN;
                curr[j] = matrix[i][j] + max({up, leftDiag, rightDiag});
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};
