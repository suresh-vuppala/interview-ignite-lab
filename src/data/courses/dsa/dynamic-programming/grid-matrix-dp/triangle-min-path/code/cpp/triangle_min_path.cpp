#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        vector<int> dp = tri.back(); // Start from bottom row
        for (int i = tri.size()-2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = tri[i][j] + min(dp[j], dp[j+1]);
        return dp[0];
    }
};