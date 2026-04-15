#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Check all time points — O(N * maxTime) or O(N²)
// ============================================================
class Solution1 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // Sort starts and ends separately, sweep
        int n = intervals.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; i++) { starts[i] = intervals[i][0]; ends[i] = intervals[i][1]; }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int rooms = 0, maxRooms = 0, ei = 0;
        for (int si = 0; si < n; si++) {
            if (starts[si] < ends[ei]) rooms++;
            else ei++;
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};

// ============================================================
// Solution 2: Min-heap of end times — O(N log N)
// ============================================================
class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq; // min-heap of end times
        for (auto& iv : intervals) {
            if (!pq.empty() && pq.top() <= iv[0]) pq.pop(); // Reuse room
            pq.push(iv[1]);
        }
        return pq.size();
    }
};
