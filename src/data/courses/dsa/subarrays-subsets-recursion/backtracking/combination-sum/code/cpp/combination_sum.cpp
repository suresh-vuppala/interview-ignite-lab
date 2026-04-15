#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Generate all combinations, filter by sum — O(N^target)
// ============================================================
class Solution1 {
    void generate(vector<int>& c, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(cur); return; }
        if (target < 0) return;
        for (int i = start; i < (int)c.size(); i++) {
            cur.push_back(c[i]);
            generate(c, target - c[i], i, cur, res); // Can reuse same element
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; vector<int> cur;
        generate(candidates, target, 0, cur, res); return res;
    }
};

// ============================================================
// Solution 2: Backtracking with sort + early termination — pruned O(N^target)
// ============================================================
class Solution2 {
    void bt(vector<int>& c, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(cur); return; }
        for (int i = start; i < (int)c.size(); i++) {
            if (c[i] > target) break; // Sorted → prune all remaining
            cur.push_back(c[i]);
            bt(c, target - c[i], i, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort for pruning
        vector<vector<int>> res; vector<int> cur;
        bt(candidates, target, 0, cur, res); return res;
    }
};
