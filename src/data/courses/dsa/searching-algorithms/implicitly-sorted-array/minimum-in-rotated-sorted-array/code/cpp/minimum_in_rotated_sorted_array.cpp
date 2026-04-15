#include <vector>
using namespace std;
// ============================================================
// Solution 1: Linear scan — O(N) Time
// ============================================================
class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];
        for (int x : nums) mn = min(mn, x);
        return mn;
    }
};

// ============================================================
// Solution 2: Binary search — O(log N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1; // Min is in right half
            else hi = mid; // Min is in left half (including mid)
        }
        return nums[lo];
    }
};
