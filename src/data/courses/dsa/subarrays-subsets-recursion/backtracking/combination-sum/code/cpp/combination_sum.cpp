// Time: O(N^(T/M)), Space: O(T/M)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;
        
        for (int i = index; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> result = sol.combinationSum(candidates, 7);
    for (auto& comb : result) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
    return 0;
}
