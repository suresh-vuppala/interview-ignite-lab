class Solution {
public:
    // Brute Force: O(n³) — Check all triplets
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to avoid duplicate triplets
        set<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < n-2; i++)
            for (int j = i+1; j < n-1; j++)
                for (int k = j+1; k < n; k++)
                    if (nums[i]+nums[j]+nums[k] == 0)
                        result.insert({nums[i], nums[j], nums[k]});
        return vector<vector<int>>(result.begin(), result.end());
    }
};