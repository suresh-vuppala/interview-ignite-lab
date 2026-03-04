def merge(intervals):
    intervals.sort()  # Sort by start time
    result = [intervals[0]]
    for start, end in intervals[1:]:
        if start <= result[-1][1]:  # Overlapping
            result[-1][1] = max(result[-1][1], end)  # Extend end
        else:
            result.append([start, end])  # Add merged interval
    return result