#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& nums, int i) {
        if (i < 0) return 0;
        return max(solve(nums, i-1), nums[i] + solve(nums, i-2));
    }
    int maxSum(vector<int>& nums) { return solve(nums, nums.size()-1); }
};

// ============================================================
// Solution 2: DP — Bottom-up with two variables — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxSum(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        for (int x : nums) { int c = max(prev1, x+prev2); prev2=prev1; prev1=c; }
        return prev1;
    }
};
