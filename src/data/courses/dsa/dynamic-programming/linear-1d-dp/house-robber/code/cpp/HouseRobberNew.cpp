#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int robMemo(int nums) {
        n = len(nums);
        if (n == 0) {
            return 0;
        if (n == 1) {
            return nums[0];
        unordered_map<int, int> memo;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    int robTab(int nums) {
        n = len(nums);
        if (n == 0) {
            return 0;
        if (n == 1) {
            return nums[0];
        dp = [0] * n;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for i in range(2, n)) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        return dp[n-1];
    }
    int rob(int nums) {
        if (!nums) {
            return 0;
        if (len(nums) == 1) {
            return nums[0];
        prev2 = nums[0];
        prev1 = max(nums[0];
        for i in range(2, len(nums))) {
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        return prev1;
    }
};
