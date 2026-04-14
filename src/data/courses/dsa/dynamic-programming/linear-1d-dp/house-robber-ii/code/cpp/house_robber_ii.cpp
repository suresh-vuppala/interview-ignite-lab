#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& nums, int i, int end) {
        if (i > end) return 0;
        return max(solve(nums, i+1, end), nums[i] + solve(nums, i+2, end));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(solve(nums, 0, n-2), solve(nums, 1, n-1));
    }
};

// ============================================================
// Solution 2: DP — Two passes of House Robber I — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
    int robLinear(vector<int>& nums, int lo, int hi) {
        int prev2 = 0, prev1 = 0;
        for (int i = lo; i <= hi; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1; prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLinear(nums, 0, n-2), robLinear(nums, 1, n-1));
    }
};
