// ============================================================
// Solution 1: DP approach — Coin Change example — O(N*amount)
// ============================================================
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution1 {
public:
    // DP always finds optimal — considers all combinations
    int coinChangeDP(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (int c : coins)
                if (c <= i) dp[i] = min(dp[i], 1 + dp[i-c]);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// ============================================================
// Solution 2: Greedy approach — pick largest coin first — O(N log N)
// ============================================================
class Solution2 {
public:
    // Greedy FAILS for some coin sets! e.g. coins={1,3,4}, amount=6
    // Greedy: 4+1+1=3 coins. Optimal: 3+3=2 coins.
    int coinChangeGreedy(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend()); // Largest first
        int count = 0;
        for (int c : coins) {
            count += amount / c;
            amount %= c;
        }
        return amount == 0 ? count : -1; // May fail!
    }
};
