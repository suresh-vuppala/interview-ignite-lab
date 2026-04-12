#include <vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0); dp[0] = 1;
        for (int coin : coins) // Coin loop OUTSIDE to avoid counting permutations
            for (int a = coin; a <= amount; a++)
                dp[a] += dp[a - coin];
        return dp[amount];
    }
};
