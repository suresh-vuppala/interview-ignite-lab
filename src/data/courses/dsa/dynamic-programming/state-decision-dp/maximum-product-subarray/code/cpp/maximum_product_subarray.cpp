#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — All subarrays — O(N²) Time
// ============================================================
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) { prod *= nums[j]; res = max(res, prod); }
        }
        return res;
    }
};

// ============================================================
// Solution 2: Track curMax and curMin — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] < 0) swap(curMax, curMin);
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);
            res = max(res, curMax);
        }
        return res;
    }
};
