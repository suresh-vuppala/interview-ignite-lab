#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all subarrays — O(N²)
// ============================================================
class Solution1 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), count = 0;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod < k) count++;
                else break;
            }
        }
        return count;
    }
};

// ============================================================
// Solution 2: Sliding Window — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int left = 0, prod = 1, count = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            count += right - left + 1; // All subarrays ending at right
        }
        return count;
    }
};
