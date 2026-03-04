class NonOverlappingIntervals {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]); // Sort by end time
        int count = 1, end = intervals[0][1]; // Count non-overlapping intervals
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= end) { // No overlap
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.length - count; // Total - non-overlapping = to remove
    }
}