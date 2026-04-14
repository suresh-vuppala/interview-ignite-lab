#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^(M+N)) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i<0||j<0||grid[i][j]==1) return 0;
        if (i==0&&j==0) return 1;
        return solve(grid,i-1,j) + solve(grid,i,j-1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        return solve(grid, grid.size()-1, grid[0].size()-1);
    }
};

// ============================================================
// Solution 2: DP — 1D array with obstacle check — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long> dp(n, 0);
        dp[0] = 1;
        for (auto& row : grid) {
            for (int j = 0; j < n; j++) {
                if (row[j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
