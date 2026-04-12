class Solution {
    public int maxPathSum(int[][] mat) {
        int m=mat.length,n=mat[0].length; int[] dp=mat[0].clone();
        for(int i=1;i<m;i++){int[] nd=new int[n];
            for(int j=0;j<n;j++){int b=dp[j];if(j>0)b=Math.max(b,dp[j-1]);if(j<n-1)b=Math.max(b,dp[j+1]);nd[j]=mat[i][j]+b;}dp=nd;}
        int max=dp[0]; for(int v:dp) max=Math.max(max,v); return max;
    }
}