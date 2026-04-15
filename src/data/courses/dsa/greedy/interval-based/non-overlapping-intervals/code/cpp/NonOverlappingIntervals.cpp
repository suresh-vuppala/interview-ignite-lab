#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: DP — longest non-overlapping subsequence — O(N²)
// ============================================================
class Solution1 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> dp(n, 1); // LIS-style: max non-overlapping ending at i
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (intervals[j][1] <= intervals[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
        return n - *max_element(dp.begin(), dp.end());
    }
};

// ============================================================
// Solution 2: Greedy — sort by end, count non-overlapping — O(N log N)
// ============================================================
class Solution2 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        int keep = 1, end = intervals[0][1];
        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] >= end) { keep++; end = intervals[i][1]; }
        }
        return intervals.size() - keep;
    }
};
