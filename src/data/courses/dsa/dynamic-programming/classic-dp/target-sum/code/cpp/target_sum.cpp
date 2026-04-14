#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& nums, int target, int i) {
        if (i < 0) return target == 0 ? 1 : 0;
        return solve(nums, target-nums[i], i-1) + solve(nums, target+nums[i], i-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) { return solve(nums, target, nums.size()-1); }
};

// ============================================================
// Solution 2: DP — Subset sum transformation — O(N*S) Time, O(S) Space
// ============================================================
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0; for (int x : nums) sum += x;
        if ((sum + target) % 2 != 0 || sum + target < 0) return 0;
        int s = (sum + target) / 2;
        vector<int> dp(s+1, 0); dp[0] = 1;
        for (int x : nums)
            for (int j = s; j >= x; j--)
                dp[j] += dp[j-x];
        return dp[s];
    }
};
