#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all pairs for overlap — O(N²)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto& iv : intervals) {
            bool merged = false;
            for (auto& r : res) {
                if (iv[0] <= r[1]) { r[1] = max(r[1], iv[1]); merged = true; break; }
            }
            if (!merged) res.push_back(iv);
        }
        return res;
    }
};

// ============================================================
// Solution 2: Sort + single pass merge — O(N log N) Time
// ============================================================
class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
