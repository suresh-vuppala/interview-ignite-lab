class Solution {
    public int unboundedKnapsack(int W, int[] wt, int[] val) {
        int[] dp = new int[W+1];
        for (int i=0;i<wt.length;i++)
            for (int w=wt[i];w<=W;w++) dp[w]=Math.max(dp[w],dp[w-wt[i]]+val[i]);
        return dp[W];
    }
}