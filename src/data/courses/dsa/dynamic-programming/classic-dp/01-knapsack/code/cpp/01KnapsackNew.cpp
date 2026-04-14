#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& wt, vector<int>& val, int W, int i) {
        if (i < 0 || W == 0) return 0;
        if (wt[i] > W) return solve(wt, val, W, i-1);
        return max(solve(wt, val, W, i-1), val[i] + solve(wt, val, W-wt[i], i-1));
    }
    int knapsack(vector<int>& wt, vector<int>& val, int W) { return solve(wt, val, W, wt.size()-1); }
};

// ============================================================
// Solution 2: DP — 1D bottom-up — O(N*W) Time, O(W) Space
// ============================================================
class Solution2 {
public:
    int knapsack(vector<int>& wt, vector<int>& val, int W) {
        int n = wt.size();
        vector<int> dp(W+1, 0);
        for (int i = 0; i < n; i++)
            for (int w = W; w >= wt[i]; w--)
                dp[w] = max(dp[w], val[i] + dp[w-wt[i]]);
        return dp[W];
    }
};
