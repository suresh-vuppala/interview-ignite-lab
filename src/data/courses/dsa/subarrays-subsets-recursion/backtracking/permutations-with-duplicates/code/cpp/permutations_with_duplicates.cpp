// Time: O(N × N!), Space: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, visited, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1])) continue;
            
            visited[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, visited, current, result);
            current.pop_back();
            visited[i] = false;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);
    for (auto& perm : result) {
        for (int num : perm) cout << num << " ";
        cout << endl;
    }
    return 0;
}
