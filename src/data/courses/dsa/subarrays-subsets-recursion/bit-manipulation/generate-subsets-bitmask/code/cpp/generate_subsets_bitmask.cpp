#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursive backtracking — O(2^N)
// ============================================================
class Solution1 {
    void backtrack(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);
        for (int j = i; j < (int)nums.size(); j++) {
            cur.push_back(nums[j]);
            backtrack(nums, j + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; vector<int> cur;
        backtrack(nums, 0, cur, res);
        return res;
    }
};

// ============================================================
// Solution 2: Bitmask enumeration — O(2^N * N)
// ============================================================
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> sub;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) sub.push_back(nums[i]);
            res.push_back(sub);
        }
        return res; // Each bit = include/exclude decision
    }
};
