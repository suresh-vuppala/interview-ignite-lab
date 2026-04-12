#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rodCutting(vector<int>& price, int n) {
        vector<int> dp(n + 1, 0);
        for (int len = 1; len <= n; len++)
            for (int i = 1; i <= len; i++)
                dp[len] = max(dp[len], price[i-1] + dp[len - i]);
        return dp[n];
    }
};
