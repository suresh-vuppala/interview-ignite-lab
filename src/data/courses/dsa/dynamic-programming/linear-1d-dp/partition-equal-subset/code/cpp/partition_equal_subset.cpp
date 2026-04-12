class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums)
            for (int j = target; j >= num; j--) // Reverse to avoid reuse
                dp[j] = dp[j] || dp[j - num];
        return dp[target];
    }
};
