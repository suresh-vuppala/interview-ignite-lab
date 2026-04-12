#include <vector>
using namespace std;
class Solution {
public:
    bool subsetSum(vector<int>& nums, int target) {
        vector<bool> dp(target+1, false); dp[0] = true;
        for (int num : nums)
            for (int j = target; j >= num; j--)
                dp[j] = dp[j] || dp[j-num];
        return dp[target];
    }
};
