#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(S^N) where S=amount, N=coins
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        int res = INT_MAX;
        for (int c : coins) {
            int sub = solve(coins, amount - c);
            if (sub != INT_MAX) res = min(res, 1 + sub);
        }
        return res;
    }
    int coinChange(vector<int>& coins, int amount) { int r = solve(coins, amount); return r==INT_MAX?-1:r; }
};

// ============================================================
// Solution 2: DP — Bottom-up — O(amount * N) Time, O(amount) Space
// ============================================================
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (int c : coins)
                if (c <= i) dp[i] = min(dp[i], 1 + dp[i-c]);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
