class NonOverlappingIntervals {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1]; // Sort by end time
        });
        int count = 1, end = intervals[0][1]; // Count non-overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) { // No overlap
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - count; // Total - non-overlapping = to remove
    }
};