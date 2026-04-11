class Solution {
public:
    // Brute Force: O(n⁴)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        int n = nums.size();
        for (int i=0;i<n-3;i++) for (int j=i+1;j<n-2;j++)
            for (int k=j+1;k<n-1;k++) for (int l=k+1;l<n;l++)
                if ((long)nums[i]+nums[j]+nums[k]+nums[l]==target)
                    result.insert({nums[i],nums[j],nums[k],nums[l]});
        return vector<vector<int>>(result.begin(), result.end());
    }
};