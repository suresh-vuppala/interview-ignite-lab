class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum=0; for(int n:nums) sum+=n;
        if((sum+target)%2!=0||sum+target<0) return 0;
        int s=(sum+target)/2; int[] dp=new int[s+1]; dp[0]=1;
        for(int n:nums) for(int j=s;j>=n;j--) dp[j]+=dp[j-n];
        return dp[s];
    }
}