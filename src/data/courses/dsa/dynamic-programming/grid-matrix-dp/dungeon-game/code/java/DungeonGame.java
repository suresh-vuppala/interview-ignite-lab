class Solution {
    public int calculateMinimumHP(int[][] d) {
        int m=d.length,n=d[0].length; int[] dp=new int[n+1];
        java.util.Arrays.fill(dp,Integer.MAX_VALUE); dp[n-1]=1;
        for(int i=m-1;i>=0;i--){int[] nd=new int[n+1]; java.util.Arrays.fill(nd,Integer.MAX_VALUE);
            for(int j=n-1;j>=0;j--) nd[j]=Math.max(1,Math.min(dp[j],nd[j+1])-d[i][j]); dp=nd;}
        return dp[0];
    }
}