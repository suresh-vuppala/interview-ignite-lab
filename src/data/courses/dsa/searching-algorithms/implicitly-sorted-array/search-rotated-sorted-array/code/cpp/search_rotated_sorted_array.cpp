class Solution {
public:
    // O(log n) — Modified binary search: identify sorted half, check target range
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            
            // Left half is sorted
            if (nums[lo] <= nums[mid]) {
                if (target >= nums[lo] && target < nums[mid])
                    hi = mid - 1; // Target is in sorted left half
                else
                    lo = mid + 1; // Target is in right half
            }
            // Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[hi])
                    lo = mid + 1; // Target is in sorted right half
                else
                    hi = mid - 1; // Target is in left half
            }
        }
        return -1;
    }
};