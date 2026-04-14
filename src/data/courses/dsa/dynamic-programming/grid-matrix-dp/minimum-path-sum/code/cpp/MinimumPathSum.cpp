#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^(M+N)) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i==0&&j==0) return grid[0][0];
        if (i<0||j<0) return 1e9;
        return grid[i][j] + min(solve(grid,i-1,j), solve(grid,i,j-1));
    }
    int minPathSum(vector<vector<int>>& grid) { return solve(grid, grid.size()-1, grid[0].size()-1); }
};

// ============================================================
// Solution 2: DP — 1D bottom-up — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> dp(n);
        dp[0]=grid[0][0];
        for(int j=1;j<n;j++) dp[j]=dp[j-1]+grid[0][j];
        for(int i=1;i<m;i++) {
            dp[0]+=grid[i][0];
            for(int j=1;j<n;j++) dp[j]=grid[i][j]+min(dp[j],dp[j-1]);
        }
        return dp[n-1];
    }
};
