class Solution {
    public int minDistance(String w1, String w2) {
        int m=w1.length(),n=w2.length(); int[] dp=new int[n+1];
        for(int j=0;j<=n;j++) dp[j]=j;
        for(int i=1;i<=m;i++){int prev=dp[0]; dp[0]=i;
            for(int j=1;j<=n;j++){int t=dp[j];
                if(w1.charAt(i-1)==w2.charAt(j-1)) dp[j]=prev;
                else dp[j]=1+Math.min(prev,Math.min(dp[j],dp[j-1])); prev=t;}}
        return dp[n];
    }
}