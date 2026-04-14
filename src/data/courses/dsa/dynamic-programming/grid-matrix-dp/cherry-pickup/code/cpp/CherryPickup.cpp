#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — two robots moving simultaneously
// ============================================================
class Solution1 {
public:
    int solve(vector<vector<int>>& grid, int r, int c1, int c2) {
        int m=grid.size(), n=grid[0].size();
        if(r>=m||c1<0||c1>=n||c2<0||c2>=n) return 0;
        int cherries = grid[r][c1] + (c1!=c2 ? grid[r][c2] : 0);
        int best=0;
        for(int d1=-1;d1<=1;d1++)
            for(int d2=-1;d2<=1;d2++)
                best=max(best,solve(grid,r+1,c1+d1,c2+d2));
        return cherries+best;
    }
    int cherryPickup(vector<vector<int>>& grid) { return solve(grid,0,0,grid[0].size()-1); }
};

// ============================================================
// Solution 2: DP — 3D DP (row, col1, col2) — O(M*N²) Time
// ============================================================
class Solution2 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int r=m-1;r>=0;r--) {
            vector<vector<int>> ndp(n, vector<int>(n, 0));
            for(int c1=0;c1<n;c1++) for(int c2=0;c2<n;c2++) {
                int val=grid[r][c1]+(c1!=c2?grid[r][c2]:0);
                int best=0;
                for(int d1=-1;d1<=1;d1++) for(int d2=-1;d2<=1;d2++) {
                    int nc1=c1+d1, nc2=c2+d2;
                    if(nc1>=0&&nc1<n&&nc2>=0&&nc2<n) best=max(best,dp[nc1][nc2]);
                }
                ndp[c1][c2]=val+best;
            }
            dp=ndp;
        }
        return dp[0][n-1];
    }
};
