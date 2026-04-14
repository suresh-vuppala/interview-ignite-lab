#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& nums, int i, int prev) {
        if (i >= (int)nums.size()) return 0;
        int skip = solve(nums, i+1, prev);
        if (nums[i] > prev) return max(skip, 1 + solve(nums, i+1, nums[i]));
        return skip;
    }
    int lengthOfLIS(vector<int>& nums) { return solve(nums, 0, INT_MIN); }
};

// ============================================================
// Solution 2: DP — O(N²) bottom-up or O(N log N) patience sort
// ============================================================
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails; // Patience sorting — O(N log N)
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) tails.push_back(x);
            else *it = x;
        }
        return tails.size();
    }
};
