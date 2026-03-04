def min_meeting_rooms(intervals):
    start = sorted([i[0] for i in intervals])  # Sort start times
    end = sorted([i[1] for i in intervals])  # Sort end times
    rooms, end_ptr = 0, 0
    for i in range(len(intervals)):
        if start[i] < end[end_ptr]:  # Meeting starts before earliest ends
            rooms += 1  # Need new room
        else:
            end_ptr += 1  # Reuse room
    return rooms