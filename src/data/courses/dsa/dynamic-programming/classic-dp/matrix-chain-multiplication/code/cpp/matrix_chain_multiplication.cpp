#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int matrixChainMultiplication(vector<int>& dims) {
        int n = dims.size() - 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; len++)
            for (int i = 0; i <= n-len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+dims[i]*dims[k+1]*dims[j+1]);
            }
        return dp[0][n-1];
    }
};
