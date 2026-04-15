#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all windows — O(N*K)
// ============================================================
class Solution1 {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        int n = nums.size(), maxSum = INT_MIN;
        for (int i = 0; i <= n - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

// ============================================================
// Solution 2: Sliding Window — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int maxSum = sum;
        for (int i = k; i < (int)nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
