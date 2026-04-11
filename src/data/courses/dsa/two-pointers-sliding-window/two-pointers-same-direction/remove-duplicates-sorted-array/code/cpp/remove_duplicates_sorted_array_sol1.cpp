class Solution {
public:
    // Extra Array: O(n) space — Copy unique elements
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique;
        unique.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != unique.back()) unique.push_back(nums[i]);
        }
        for (int i = 0; i < unique.size(); i++) nums[i] = unique[i];
        return unique.size();
    }
};