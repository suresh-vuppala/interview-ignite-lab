#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — try all subsets, pick max non-overlapping — O(2^N)
// ============================================================
class Solution1 {
    int maxActivities(vector<vector<int>>& acts, int i, int lastEnd) {
        if (i >= (int)acts.size()) return 0;
        int skip = maxActivities(acts, i+1, lastEnd);
        int take = 0;
        if (acts[i][0] >= lastEnd)
            take = 1 + maxActivities(acts, i+1, acts[i][1]);
        return max(skip, take);
    }
public:
    int activitySelection(vector<vector<int>>& activities) {
        sort(activities.begin(), activities.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        return maxActivities(activities, 0, 0);
    }
};

// ============================================================
// Solution 2: Greedy — sort by end time, pick earliest finish — O(N log N)
// ============================================================
class Solution2 {
public:
    int activitySelection(vector<vector<int>>& activities) {
        sort(activities.begin(), activities.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
        int count = 1, lastEnd = activities[0][1];
        for (int i = 1; i < (int)activities.size(); i++) {
            if (activities[i][0] >= lastEnd) {
                count++;
                lastEnd = activities[i][1];
            }
        }
        return count;
    }
};
