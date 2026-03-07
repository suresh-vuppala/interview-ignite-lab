#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int maxSubArrayMemo(int nums) {
        n = len(nums);
        unordered_map<int, int> memo;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    int maxSubArrayTab(int nums) {
        n = len(nums);
        dp = [0] * n;
        dp[0] = nums[0];
        max_sum = dp[0];
        for i in range(1, n)) {
            dp[i] = max(nums[i], nums[i] + dp[i-1]);
            max_sum = max(max_sum, dp[i]);
        return max_sum;
    }
    int maxSubArray(int nums) {
        max_ending_here = max_so_far = nums[0];
        for i in range(1, len(nums))) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        return max_so_far;
    }
};
