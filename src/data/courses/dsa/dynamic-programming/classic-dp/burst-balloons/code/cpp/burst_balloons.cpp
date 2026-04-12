#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = {1}; // Add boundary 1s
        for (int x : nums) a.push_back(x);
        a.push_back(1);
        int m = a.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 1; len <= n; len++)
            for (int i = 1; i <= n-len+1; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + a[i-1]*a[k]*a[j+1] + dp[k+1][j]);
            }
        return dp[1][n];
    }
};
