#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int knapsack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < n; i++)
            for (int w = W; w >= wt[i]; w--) // RIGHT to LEFT — prevents reuse
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        return dp[W];
    }
};
