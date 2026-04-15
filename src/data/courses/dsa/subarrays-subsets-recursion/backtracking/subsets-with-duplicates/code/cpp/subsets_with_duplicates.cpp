#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Generate all then deduplicate via set — O(2^N * N log N)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> unique;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> sub;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) sub.push_back(nums[i]);
            unique.insert(sub);
        }
        return vector<vector<int>>(unique.begin(), unique.end());
    }
};

// ============================================================
// Solution 2: Sort + Skip at Same Recursion Level — O(2^N)
// ============================================================
class Solution2 {
    void bt(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);
        for (int i = start; i < (int)nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue; // Skip dups at same level
            cur.push_back(nums[i]);
            bt(nums, i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res; vector<int> cur;
        bt(nums, 0, cur, res); return res;
    }
};
