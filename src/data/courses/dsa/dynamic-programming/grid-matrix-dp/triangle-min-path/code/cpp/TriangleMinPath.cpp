#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<vector<int>>& tri, int i, int j) {
        if(i==(int)tri.size()) return 0;
        return tri[i][j]+min(solve(tri,i+1,j),solve(tri,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) { return solve(triangle,0,0); }
};

// ============================================================
// Solution 2: DP — Bottom-up on last row — O(N²) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        vector<int> dp(tri.back());
        for(int i=tri.size()-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                dp[j]=tri[i][j]+min(dp[j],dp[j+1]);
        return dp[0];
    }
};
