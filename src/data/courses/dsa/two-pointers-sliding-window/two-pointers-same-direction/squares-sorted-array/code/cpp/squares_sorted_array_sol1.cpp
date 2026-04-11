class Solution {
public:
    // Square then sort: O(n log n)
    vector<int> sortedSquares(vector<int>& nums) {
        for (int& n : nums) n = n * n;   // Square all elements
        sort(nums.begin(), nums.end());    // Sort
        return nums;
    }
};