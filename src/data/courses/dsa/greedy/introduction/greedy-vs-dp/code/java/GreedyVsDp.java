class GreedyVsDP {
    // Greedy: Activity Selection - Choose activities that finish earliest
    public int maxActivities(int[] start, int[] end) {
        Arrays.sort(end); // Sort by end time
        int count = 1, lastEnd = end[0];
        for (int i = 1; i < end.length; i++) {
            if (start[i] >= lastEnd) { // No overlap with previous activity
                count++;
                lastEnd = end[i];
            }
        }
        return count;
    }
    
    // DP: 0/1 Knapsack - Need to consider all possibilities
    public int knapsack(int[] wt, int[] val, int W) {
        int n = wt.length;
        int[] dp = new int[W + 1]; // dp[w] = max value with weight w
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) { // Iterate backwards to avoid using same item twice
                dp[w] = Math.max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
}