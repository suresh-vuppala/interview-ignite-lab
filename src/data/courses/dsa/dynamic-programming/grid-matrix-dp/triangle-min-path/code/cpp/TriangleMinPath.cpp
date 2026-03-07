#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    int minimumTotalRecursive(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
    }
    
private:
    int solve(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()) return 0;
        return triangle[i][j] + min(solve(triangle, i+1, j), solve(triangle, i+1, j+1));
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N²) | Space: O(N²)
    int minimumTotalMemo(vector<vector<int>>& triangle) {
        unordered_map<string, int> memo;
        return solveMemo(triangle, 0, 0, memo);
    }
    
private:
    int solveMemo(vector<vector<int>>& triangle, int i, int j, unordered_map<string, int>& memo) {
        if (i == triangle.size()) return 0;
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        memo[key] = triangle[i][j] + min(solveMemo(triangle, i+1, j, memo), 
                                         solveMemo(triangle, i+1, j+1, memo));
        return memo[key];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N²) | Space: O(N²)
    int minimumTotalTab(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(i+1);
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                } else {
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(N²) | Space: O(N)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
