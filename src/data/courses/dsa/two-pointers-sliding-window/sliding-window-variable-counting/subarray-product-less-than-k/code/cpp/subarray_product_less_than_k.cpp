// ============================================================
// Subarray Product Less Than K
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = i; j < nums.size(); j++) {
                product *= nums[j];
                if (product >= k) break;
                count++;
            }
        }
        return count;
    }
};

// ============================================================
// Solution 2: Sliding Window (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // No positive product < 1

        int product = 1, left = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right]; // Expand window

            // Shrink while product too large
            while (product >= k) {
                product /= nums[left]; // Divide out leaving element
                left++;
            }

            // All subarrays ending at right are valid
            count += right - left + 1;
        }

        return count;
    }
};
