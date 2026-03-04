def erase_overlap_intervals(intervals):
    intervals.sort(key=lambda x: x[1])  # Sort by end time
    count, end = 1, intervals[0][1]  # Count non-overlapping intervals
    for i in range(1, len(intervals)):
        if intervals[i][0] >= end:  # No overlap
            count += 1
            end = intervals[i][1]
    return len(intervals) - count  # Total - non-overlapping = to remove