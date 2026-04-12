#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int unboundedKnapsack(int W, vector<int>& wt, vector<int>& val) {
        vector<int> dp(W + 1, 0);
        for (int i = 0; i < (int)wt.size(); i++)
            for (int w = wt[i]; w <= W; w++) // LEFT to RIGHT — allows reuse
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        return dp[W];
    }
};
