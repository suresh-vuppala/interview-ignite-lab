class Solution {
public:
    // Fewer writes — swap val with end element
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), i = 0;
        while (i < n) {
            if (nums[i] == val) { nums[i] = nums[n-1]; n--; } // Swap with end
            else i++;  // Only advance if current is not val
        }
        return n;
    }
};