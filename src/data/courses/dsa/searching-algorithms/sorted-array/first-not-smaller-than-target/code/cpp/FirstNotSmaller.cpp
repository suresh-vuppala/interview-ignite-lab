#include <vector>
using namespace std;
// ============================================================
// Solution 1: Linear scan — O(N) Time
// ============================================================
class Solution1 {
public:
    int firstNotSmaller(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] >= target) return i;
        return nums.size(); // All smaller
    }
};

// ============================================================
// Solution 2: Binary search (lower_bound) — O(log N) Time
// ============================================================
class Solution2 {
public:
    int firstNotSmaller(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(); // hi = N for "not found"
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
