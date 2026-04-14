#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^amount) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& coins, int amount, int i) {
        if (amount == 0) return 1;
        if (amount < 0 || i < 0) return 0;
        return solve(coins, amount, i-1) + solve(coins, amount-coins[i], i);
    }
    int change(int amount, vector<int>& coins) { return solve(coins, amount, coins.size()-1); }
};

// ============================================================
// Solution 2: DP — 1D bottom-up — O(amount * N) Time, O(amount) Space
// ============================================================
class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int c : coins)
            for (int a = c; a <= amount; a++)
                dp[a] += dp[a-c];
        return dp[amount];
    }
};
