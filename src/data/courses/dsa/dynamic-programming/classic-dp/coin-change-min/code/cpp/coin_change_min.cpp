#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // amount+1 = "impossible"
        dp[0] = 0;
        for (int coin : coins)
            for (int a = coin; a <= amount; a++) // Left to right — unlimited
                dp[a] = min(dp[a], dp[a - coin] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
