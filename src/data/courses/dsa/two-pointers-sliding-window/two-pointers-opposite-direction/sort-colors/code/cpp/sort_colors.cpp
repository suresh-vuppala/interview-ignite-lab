class Solution {
public:
    // O(n) time, O(1) space — Dutch National Flag: 3 pointers
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while (mid <= hi) {
            if (nums[mid] == 0)      swap(nums[lo++], nums[mid++]); // Move 0 to front
            else if (nums[mid] == 1) mid++;                          // 1 stays in middle
            else                     swap(nums[mid], nums[hi--]);    // Move 2 to back
        }
    }
};