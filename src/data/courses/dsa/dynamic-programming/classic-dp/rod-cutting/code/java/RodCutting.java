class Solution {
    public int rodCutting(int[] price, int n) {
        int[] dp=new int[n+1];
        for (int l=1;l<=n;l++) for (int i=1;i<=l;i++) dp[l]=Math.max(dp[l],price[i-1]+dp[l-i]);
        return dp[n];
    }
}