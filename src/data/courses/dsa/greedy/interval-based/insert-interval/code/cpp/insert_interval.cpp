#include <vector>
using namespace std;
// ============================================================
// Solution 1: Add then merge all — O(N log N)
// ============================================================
#include <algorithm>
class Solution1 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] <= res.back()[1]) res.back()[1] = max(res.back()[1], intervals[i][1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};

// ============================================================
// Solution 2: Three-part scan — before, merge, after — O(N)
// ============================================================
class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        // Part 1: intervals entirely before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) res.push_back(intervals[i++]);
        // Part 2: merge overlapping
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // Part 3: intervals entirely after
        while (i < n) res.push_back(intervals[i++]);
        return res;
    }
};
