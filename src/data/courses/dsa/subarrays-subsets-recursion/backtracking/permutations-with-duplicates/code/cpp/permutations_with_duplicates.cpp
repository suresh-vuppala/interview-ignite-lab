#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& curr, vector<vector<int>>& result) {
    if (curr.size() == nums.size()) {
        result.push_back(curr);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1]))
            continue;
        used[i] = true;
        curr.push_back(nums[i]);
        backtrack(nums, used, curr, result);
        curr.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> curr;
    vector<bool> used(nums.size());
    sort(nums.begin(), nums.end());
    backtrack(nums, used, curr, result);
    return result;
}