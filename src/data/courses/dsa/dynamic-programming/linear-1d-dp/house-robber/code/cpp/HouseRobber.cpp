#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int robMemo(vector<int>& nums) {
        unordered_map<int, int> memo;
        return dpMemo(nums.size() - 1, nums, memo);
    }
    
    int dpMemo(int i, vector<int>& nums, unordered_map<int, int>& memo) {
        if (i < 0) return 0;
        if (memo.count(i)) return memo[i];
        memo[i] = max(nums[i] + dpMemo(i-2, nums, memo), dpMemo(i-1, nums, memo));
        return memo[i];
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    int robTab(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
    
    // ============ SPACE OPTIMIZED ============
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};