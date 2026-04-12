class Solution {
    public int longestCommonSubsequence(String t1, String t2) {
        int m=t1.length(),n=t2.length(); int[] dp=new int[n+1];
        for(int i=1;i<=m;i++){int prev=0;
            for(int j=1;j<=n;j++){int temp=dp[j];
                dp[j]=t1.charAt(i-1)==t2.charAt(j-1)?prev+1:Math.max(dp[j],dp[j-1]);prev=temp;}}
        return dp[n];
    }
}