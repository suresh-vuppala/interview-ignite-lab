class Solution {
public:
    // Optimal: Single pass — Dutch National Flag
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while (mid <= hi) {
            if (nums[mid] == 0) swap(nums[lo++], nums[mid++]);      // Move 0 to front
            else if (nums[mid] == 1) mid++;                          // 1 stays in middle
            else /* nums[mid] == 2 */ swap(nums[mid], nums[hi--]);   // Move 2 to back
            // Note: don't advance mid after swap with hi — swapped element is unknown
        }
    }
};