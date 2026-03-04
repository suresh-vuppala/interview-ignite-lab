class MeetingRoomsII {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end()); // Sort start times
        sort(end.begin(), end.end()); // Sort end times
        
        int rooms = 0, endPtr = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] < end[endPtr]) { // Meeting starts before earliest ends
                rooms++; // Need new room
            } else {
                endPtr++; // Reuse room
            }
        }
        return rooms;
    }
};