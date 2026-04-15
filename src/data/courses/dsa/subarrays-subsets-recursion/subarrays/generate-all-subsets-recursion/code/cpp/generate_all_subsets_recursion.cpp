#include <vector>
using namespace std;
// ============================================================
// Solution 1: Bitmask — O(2^N * N)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> sub;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) sub.push_back(nums[i]);
            result.push_back(sub);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Backtracking — include/exclude at each index — O(2^N)
// ============================================================
class Solution2 {
    void bt(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur); // Every prefix is a valid subset
        for (int j = i; j < (int)nums.size(); j++) {
            cur.push_back(nums[j]);
            bt(nums, j + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res; vector<int> cur;
        bt(nums, 0, cur, res); return res;
    }
};
