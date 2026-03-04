class MergeIntervals {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]); // Sort by start time
        List<int[]> result = new ArrayList<>();
        int[] current = intervals[0];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= current[1]) { // Overlapping
                current[1] = Math.max(current[1], intervals[i][1]); // Extend end
            } else {
                result.add(current); // Add merged interval
                current = intervals[i];
            }
        }
        result.add(current);
        return result.toArray(new int[result.size()][]);
    }
}