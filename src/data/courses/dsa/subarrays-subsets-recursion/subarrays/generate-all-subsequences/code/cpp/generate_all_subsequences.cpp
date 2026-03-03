#include <vector>
using namespace std;

void generate(vector<int>& arr, int i, vector<int>& curr, vector<vector<int>>& result) {
    if (i == arr.size()) {
        result.push_back(curr);
        return;
    }
    generate(arr, i+1, curr, result);
    curr.push_back(arr[i]);
    generate(arr, i+1, curr, result);
    curr.pop_back();
}

vector<vector<int>> generateSubsequences(vector<int>& arr) {
    vector<vector<int>> result;
    vector<int> curr;
    generate(arr, 0, curr, result);
    return result;
}