#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all subarrays — O(N²)
// ============================================================
class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= target) { minLen = min(minLen, j - i + 1); break; }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

// ============================================================
// Solution 2: Sliding Window — expand right, shrink left — O(N)
// ============================================================
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLen = INT_MAX;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
