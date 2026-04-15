#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Generate all then deduplicate via set — O(N! * N)
// ============================================================
class Solution1 {
    void bt(vector<int>& nums, int start, set<vector<int>>& res) {
        if (start == (int)nums.size()) { res.insert(nums); return; }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[start], nums[i]);
            bt(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res; bt(nums, 0, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};

// ============================================================
// Solution 2: Sort + Skip Duplicates at same level — O(N! * N)
// ============================================================
class Solution2 {
    void bt(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) { res.push_back(cur); return; }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue; // Skip dup
            used[i] = true; cur.push_back(nums[i]);
            bt(nums, used, cur, res);
            cur.pop_back(); used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; vector<int> cur; vector<bool> used(nums.size(), false);
        bt(nums, used, cur, res); return res;
    }
};
