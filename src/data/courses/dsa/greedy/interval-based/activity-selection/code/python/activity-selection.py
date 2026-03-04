def max_activities(start, end):
    activities = sorted(zip(start, end), key=lambda x: x[1])  # Sort by end time
    count, last_end = 1, activities[0][1]  # Select first activity
    for s, e in activities[1:]:
        if s >= last_end:  # No overlap
            count += 1
            last_end = e
    return count