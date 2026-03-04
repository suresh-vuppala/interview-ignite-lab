class MeetingRoomsII {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        int[] start = new int[n], end = new int[n];
        for (int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start); // Sort start times
        Arrays.sort(end); // Sort end times
        
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
}