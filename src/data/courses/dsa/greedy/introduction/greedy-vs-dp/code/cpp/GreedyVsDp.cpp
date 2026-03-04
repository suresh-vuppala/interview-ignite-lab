class GreedyVsDP {
public:
    // Greedy: Activity Selection - Choose activities that finish earliest
    int maxActivities(vector<int>& start, vector<int>& end) {
        sort(end.begin(), end.end()); // Sort by end time
        int count = 1, lastEnd = end[0];
        for (int i = 1; i < end.size(); i++) {
            if (start[i] >= lastEnd) { // No overlap with previous activity
                count++;
                lastEnd = end[i];
            }
        }
        return count;
    }
    
    // DP: 0/1 Knapsack - Need to consider all possibilities
    int knapsack(vector<int>& wt, vector<int>& val, int W) {
        int n = wt.size();
        vector<int> dp(W + 1, 0); // dp[w] = max value with weight w
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) { // Iterate backwards to avoid using same item twice
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }
        return dp[W];
    }
};