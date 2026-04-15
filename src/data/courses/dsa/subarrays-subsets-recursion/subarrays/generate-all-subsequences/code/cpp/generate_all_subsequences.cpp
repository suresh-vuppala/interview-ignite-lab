#include <vector>
using namespace std;
// ============================================================
// Solution 1: Bitmask iteration — O(2^N * N)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> subsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> sub;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) sub.push_back(nums[i]);
            result.push_back(sub);
        }
        return result; // Iterative, easy to understand
    }
};

// ============================================================
// Solution 2: Include/Exclude Recursion — O(2^N)
// ============================================================
class Solution2 {
    void solve(vector<int>& nums, int idx, vector<int>& cur, vector<vector<int>>& res) {
        if (idx == (int)nums.size()) { res.push_back(cur); return; }
        solve(nums, idx + 1, cur, res);             // Exclude
        cur.push_back(nums[idx]);
        solve(nums, idx + 1, cur, res);             // Include
        cur.pop_back();                              // Backtrack
    }
public:
    vector<vector<int>> subsequences(vector<int>& nums) {
        vector<vector<int>> res; vector<int> cur;
        solve(nums, 0, cur, res); return res;
    }
};
