class ActivitySelection {
    public int maxActivities(int[] start, int[] end) {
        int n = start.length;
        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i] = new int[]{start[i], end[i]};
        }
        Arrays.sort(activities, (a, b) -> a[1] - b[1]); // Sort by end time
        
        int count = 1, lastEnd = activities[0][1]; // Select first activity
        for (int i = 1; i < n; i++) {
            if (activities[i][0] >= lastEnd) { // No overlap
                count++;
                lastEnd = activities[i][1];
            }
        }
        return count;
    }
}