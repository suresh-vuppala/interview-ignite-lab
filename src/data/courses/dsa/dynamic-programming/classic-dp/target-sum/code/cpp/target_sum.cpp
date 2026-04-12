#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0; for (int n:nums) sum += n;
        if ((sum+target)%2 != 0 || sum+target < 0) return 0;
        int subsetSum = (sum + target) / 2;
        vector<int> dp(subsetSum + 1, 0); dp[0] = 1;
        for (int num : nums)
            for (int j = subsetSum; j >= num; j--)
                dp[j] += dp[j - num];
        return dp[subsetSum];
    }
};
