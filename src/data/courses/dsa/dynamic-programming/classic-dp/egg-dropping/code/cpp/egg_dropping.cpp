#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(N * 2^K) Time
// ============================================================
class Solution1 {
public:
    int solve(int k, int n) {
        if (n <= 1 || k == 1) return n;
        int res = INT_MAX;
        for (int i = 1; i <= n; i++)
            res = min(res, 1 + max(solve(k-1, i-1), solve(k, n-i)));
        return res;
    }
    int superEggDrop(int k, int n) { return solve(k, n); }
};

// ============================================================
// Solution 2: DP — O(K * N log N) with binary search optimization
// ============================================================
class Solution2 {
public:
    int superEggDrop(int k, int n) {
        // dp[m][k] = max floors checkable with m moves and k eggs
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        int m = 0;
        while (dp[m][k] < n) {
            m++;
            for (int j = 1; j <= k; j++)
                dp[m][j] = dp[m-1][j-1] + dp[m-1][j] + 1;
        }
        return m;
    }
};
