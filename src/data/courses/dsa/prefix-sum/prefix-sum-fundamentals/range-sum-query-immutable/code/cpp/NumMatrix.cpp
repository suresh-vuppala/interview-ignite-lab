#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — sum range each query — O(N) per query
// ============================================================
class Solution1 {
    vector<int> nums;
public:
    Solution1(vector<int>& n) : nums(n) {}
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) sum += nums[i];
        return sum;
    }
};

// ============================================================
// Solution 2: Prefix Sum — O(1) per query, O(N) preprocess
// ============================================================
class Solution2 {
    vector<int> prefix;
public:
    Solution2(vector<int>& nums) : prefix(nums.size() + 1, 0) {
        for (int i = 0; i < (int)nums.size(); i++) prefix[i+1] = prefix[i] + nums[i];
    }
    int sumRange(int left, int right) { return prefix[right+1] - prefix[left]; }
};
