class Solution {
public:
    // O(n * 2^n) — Sort first, skip duplicate elements at each level
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to group duplicates
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    void backtrack(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue; // Skip duplicates
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
};