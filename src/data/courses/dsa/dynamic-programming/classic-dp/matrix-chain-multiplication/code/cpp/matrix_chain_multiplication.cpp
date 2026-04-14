#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& dims, int i, int j) {
        if (i >= j) return 0;
        int res = INT_MAX;
        for (int k = i; k < j; k++)
            res = min(res, solve(dims,i,k) + solve(dims,k+1,j) + dims[i-1]*dims[k]*dims[j]);
        return res;
    }
    int mcm(vector<int>& dims) { return solve(dims, 1, dims.size()-1); }
};

// ============================================================
// Solution 2: DP — Bottom-up gap method — O(N³) Time, O(N²) Space
// ============================================================
class Solution2 {
public:
    int mcm(vector<int>& dims) {
        int n = dims.size() - 1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int len = 2; len <= n; len++)
            for (int i = 1; i <= n-len+1; i++) {
                int j = i+len-1; dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+dims[i-1]*dims[k]*dims[j]);
            }
        return dp[1][n];
    }
};
