class Solution {
    public int uniquePathsWithObstacles(int[][] g) {
        int n=g[0].length; long[] dp=new long[n]; dp[0]=1;
        for (int[] r:g) for (int j=0;j<n;j++) { if(r[j]==1) dp[j]=0; else if(j>0) dp[j]+=dp[j-1]; }
        return (int)dp[n-1];
    }
}