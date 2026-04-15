#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Generate all then deduplicate — O(2^N * N)
// ============================================================
class Solution1 {
    void bt(vector<int>& c, int target, int start, vector<int>& cur, set<vector<int>>& res) {
        if (target == 0) { res.insert(cur); return; }
        if (target < 0) return;
        for (int i = start; i < (int)c.size(); i++) {
            cur.push_back(c[i]);
            bt(c, target - c[i], i + 1, cur, res); // No reuse
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> res; vector<int> cur;
        bt(candidates, target, 0, cur, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};

// ============================================================
// Solution 2: Sort + Skip Duplicates + No Reuse + Prune — O(2^N)
// ============================================================
class Solution2 {
    void bt(vector<int>& c, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) { res.push_back(cur); return; }
        for (int i = start; i < (int)c.size(); i++) {
            if (c[i] > target) break;                          // Prune
            if (i > start && c[i] == c[i-1]) continue;        // Skip dups at same level
            cur.push_back(c[i]);
            bt(c, target - c[i], i + 1, cur, res);            // i+1 = no reuse
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res; vector<int> cur;
        bt(candidates, target, 0, cur, res); return res;
    }
};
