class Solution {
    public int superEggDrop(int K, int N) {
        int[][] dp=new int[N+1][K+1]; int t=0;
        while(dp[t][K]<N){t++;for(int k=1;k<=K;k++)dp[t][k]=1+dp[t-1][k-1]+dp[t-1][k];}
        return t;
    }
}