// ============================================================
// Subarray Sum — Fixed Size K
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Recompute Each Window
// Time: O(N×K) | Space: O(1)
// ============================================================
class Solution1 {
public:
    bool hasSubarraySum(vector<int>& nums, int k, int target) {
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            int sum = 0;
            // Sum K elements from scratch each time
            for (int j = i; j < i + k; j++) {
                sum += nums[j];
            }
            if (sum == target) return true;
        }
        return false;
    }
};

// ============================================================
// Solution 2: Sliding Window — Running Sum (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    bool hasSubarraySum(vector<int>& nums, int k, int target) {
        // Compute first window sum
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        if (sum == target) return true;

        // Slide: subtract leaving, add entering
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];         // Add entering element
            sum -= nums[i - k];     // Subtract leaving element
            if (sum == target) return true;
        }

        return false;
    }
};
