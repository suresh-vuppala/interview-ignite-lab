#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all paths from (0,0) to (m-1,n-1)
// ============================================================
class Solution1 {
public:
    int solve(vector<vector<int>>& d, int i, int j) {
        int m=d.size(), n=d[0].size();
        if(i>=m||j>=n) return INT_MAX;
        if(i==m-1&&j==n-1) return max(1, 1-d[i][j]);
        int right=solve(d,i,j+1), down=solve(d,i+1,j);
        return max(1, min(right,down)-d[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) { return solve(dungeon,0,0); }
};

// ============================================================
// Solution 2: DP — Bottom-up from bottom-right — O(M*N) Time
// ============================================================
class Solution2 {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m=d.size(), n=d[0].size();
        vector<int> dp(n+1, INT_MAX);
        dp[n-1]=1;
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                dp[j]=max(1, min(dp[j],dp[j+1])-d[i][j]);
            }
            dp[n]=INT_MAX;
        }
        return dp[0];
    }
};
