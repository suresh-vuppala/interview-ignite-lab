#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(N! * N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int left = (i>0) ? nums[i-1] : 1;
            int right = (i<(int)nums.size()-1) ? nums[i+1] : 1;
            int coins = left * nums[i] * right;
            vector<int> rem;
            for (int j=0; j<(int)nums.size(); j++) if(j!=i) rem.push_back(nums[j]);
            res = max(res, coins + solve(rem));
        }
        return res;
    }
    int maxCoins(vector<int>& nums) { return solve(nums); }
};

// ============================================================
// Solution 2: DP — Interval DP — O(N³) Time, O(N²) Space
// ============================================================
class Solution2 {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n+2, 1);
        for (int i = 0; i < n; i++) a[i+1] = nums[i];
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int len = 1; len <= n; len++)
            for (int l = 1; l <= n-len+1; l++) {
                int r = l+len-1;
                for (int k = l; k <= r; k++)
                    dp[l][r] = max(dp[l][r], dp[l][k-1]+dp[k+1][r]+a[l-1]*a[k]*a[r+1]);
            }
        return dp[1][n];
    }
};
