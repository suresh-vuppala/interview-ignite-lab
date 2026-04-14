#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all paths from each col in row 0
// ============================================================
class Solution1 {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        int n=grid[0].size();
        if(j<0||j>=n) return INT_MIN;
        if(i==0) return grid[0][j];
        return grid[i][j]+max({solve(grid,i-1,j-1),solve(grid,i-1,j),solve(grid,i-1,j+1)});
    }
    int maxPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=INT_MIN;
        for(int j=0;j<n;j++) res=max(res,solve(grid,m-1,j));
        return res;
    }
};

// ============================================================
// Solution 2: DP — Bottom-up row by row — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int maxPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> dp(grid[0].begin(), grid[0].end());
        for(int i=1;i<m;i++) {
            vector<int> ndp(n);
            for(int j=0;j<n;j++) {
                int best=dp[j];
                if(j>0) best=max(best,dp[j-1]);
                if(j<n-1) best=max(best,dp[j+1]);
                ndp[j]=grid[i][j]+best;
            }
            dp=ndp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
