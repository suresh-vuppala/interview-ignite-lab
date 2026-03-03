#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    if (target < 0) return;
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue;
        curr.push_back(candidates[i]);
        backtrack(candidates, target-candidates[i], i+1, curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, 0, curr, result);
    return result;
}