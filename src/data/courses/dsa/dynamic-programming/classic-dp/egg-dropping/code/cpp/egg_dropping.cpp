#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int superEggDrop(int K, int N) {
        // dp[t][k] = max floors checkable with t trials and k eggs
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
        int t = 0;
        while (dp[t][K] < N) {
            t++;
            for (int k = 1; k <= K; k++)
                dp[t][k] = 1 + dp[t-1][k-1] + dp[t-1][k]; // break + no break + current
        }
        return t;
    }
};
