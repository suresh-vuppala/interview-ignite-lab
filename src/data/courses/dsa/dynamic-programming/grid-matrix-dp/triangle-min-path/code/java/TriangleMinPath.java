class Solution {
    public int minimumTotal(java.util.List<java.util.List<Integer>> tri) {
        int n=tri.size(); int[] dp=new int[n];
        for(int j=0;j<n;j++) dp[j]=tri.get(n-1).get(j);
        for(int i=n-2;i>=0;i--) for(int j=0;j<=i;j++) dp[j]=tri.get(i).get(j)+Math.min(dp[j],dp[j+1]);
        return dp[0];
    }
}