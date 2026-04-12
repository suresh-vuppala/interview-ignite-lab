#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long> dp(n, 0); dp[0] = 1;
        for (auto& row : grid) {
            for (int j = 0; j < n; j++) {
                if (row[j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};