#include <vector>
using namespace std;
// ============================================================
// Solution 1: Find pivot + two binary searches — O(log N)
// ============================================================
class Solution1 {
    int findPivot(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;
        while(lo<hi) { int mid=lo+(hi-lo)/2; if(nums[mid]>nums[hi])lo=mid+1;else hi=mid; }
        return lo;
    }
    int bs(vector<int>& nums, int lo, int hi, int target) {
        while(lo<=hi) { int mid=lo+(hi-lo)/2; if(nums[mid]==target)return mid; if(nums[mid]<target)lo=mid+1;else hi=mid-1; }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums), n = nums.size();
        int left = bs(nums, 0, pivot-1, target);
        if (left != -1) return left;
        return bs(nums, pivot, n-1, target);
    }
};

// ============================================================
// Solution 2: Single binary search — determine sorted half — O(log N)
// ============================================================
class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            if (nums[lo] <= nums[mid]) { // Left half sorted
                if (target >= nums[lo] && target < nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            } else { // Right half sorted
                if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};
