#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& price, int n) {
        if (n <= 0) return 0;
        int res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, price[i-1] + solve(price, n-i));
        return res;
    }
    int cutRod(vector<int>& price, int n) { return solve(price, n); }
};

// ============================================================
// Solution 2: DP — Bottom-up — O(N²) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int cutRod(vector<int>& price, int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                dp[i] = max(dp[i], price[j-1] + dp[i-j]);
        return dp[n];
    }
};
