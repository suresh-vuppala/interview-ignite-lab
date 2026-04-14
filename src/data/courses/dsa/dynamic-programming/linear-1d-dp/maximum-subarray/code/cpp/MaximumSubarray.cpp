#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — Check all subarrays — O(N²) Time
// ============================================================
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// ============================================================
// Solution 2: Kadane's Algorithm — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            curSum = max(nums[i], curSum + nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
