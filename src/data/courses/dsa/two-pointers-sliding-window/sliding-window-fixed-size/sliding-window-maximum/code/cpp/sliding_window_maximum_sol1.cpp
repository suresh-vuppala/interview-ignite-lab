class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= (int)nums.size()-k; i++)
            result.push_back(*max_element(nums.begin()+i, nums.begin()+i+k));
        return result;
    }
};