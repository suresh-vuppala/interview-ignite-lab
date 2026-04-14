#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    bool solve(vector<int>& nums, int target, int i) {
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;
        return solve(nums, target, i-1) || solve(nums, target-nums[i], i-1);
    }
    bool subsetSum(vector<int>& nums, int target) { return solve(nums, target, nums.size()-1); }
};

// ============================================================
// Solution 2: DP — 1D boolean array — O(N*T) Time, O(T) Space
// ============================================================
class Solution2 {
public:
    bool subsetSum(vector<int>& nums, int target) {
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (int x : nums)
            for (int t = target; t >= x; t--)
                dp[t] = dp[t] || dp[t-x];
        return dp[target];
    }
};
