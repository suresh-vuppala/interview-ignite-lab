class Solution {
    public int minPathSum(int[][] g) {
        int m=g.length,n=g[0].length; int[] dp=new int[n];
        for(int i=0;i<m;i++) for(int j=0;j<n;j++){
            if(i==0&&j==0) dp[j]=g[0][0]; else if(i==0) dp[j]=dp[j-1]+g[i][j];
            else if(j==0) dp[j]+=g[i][j]; else dp[j]=g[i][j]+Math.min(dp[j],dp[j-1]);}
        return dp[n-1];
    }
}