#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all breaks — O(2^N)
// ============================================================
class Solution1 {
public:
    int solve(int n) {
        if(n<=1) return 1;
        int res=0;
        for(int i=1;i<n;i++) res=max(res, i*max(n-i, solve(n-i)));
        return res;
    }
    int integerBreak(int n) { return solve(n); }
};

// ============================================================
// Solution 2: DP — O(N²) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0); dp[1]=1;
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
                dp[i]=max(dp[i], j*max(i-j, dp[i-j]));
        return dp[n];
    }
};
