#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursive binary search — O(log N) Time, O(log N) Stack
// ============================================================
class Solution1 {
    int bs(vector<int>& nums, int lo, int hi, int target) {
        if (lo > hi) return -1;
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) return bs(nums, mid+1, hi, target);
        return bs(nums, lo, mid-1, target);
    }
public:
    int search(vector<int>& nums, int target) { return bs(nums, 0, nums.size()-1, target); }
};

// ============================================================
// Solution 2: Iterative binary search — O(log N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};
