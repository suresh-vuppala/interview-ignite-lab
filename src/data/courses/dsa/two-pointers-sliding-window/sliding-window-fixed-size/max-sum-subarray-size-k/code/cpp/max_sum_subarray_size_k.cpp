// ============================================================
// Maximum Sum Subarray of Size K
// ============================================================

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N×K) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) sum += nums[j];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};

// ============================================================
// Solution 2: Sliding Window — Running Max (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int maxSumSubarray(vector<int>& nums, int k) {
        // First window
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int maxSum = sum;

        // Slide and track max
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k]; // Slide window
            maxSum = max(maxSum, sum);      // Update max
        }

        return maxSum;
    }
};
