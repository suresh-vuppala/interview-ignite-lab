class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount+1]; java.util.Arrays.fill(dp, amount+1); dp[0]=0;
        for (int c:coins) for (int a=c;a<=amount;a++) dp[a]=Math.min(dp[a],dp[a-c]+1);
        return dp[amount]>amount?-1:dp[amount];
    }
}