class Solution {
public:
    // O(log n) — Binary search: min is where sorted order breaks
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