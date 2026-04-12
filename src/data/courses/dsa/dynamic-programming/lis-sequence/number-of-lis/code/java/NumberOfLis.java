class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n=nums.length,maxLen=1; int[] dp=new int[n],cnt=new int[n];
        java.util.Arrays.fill(dp,1); java.util.Arrays.fill(cnt,1);
        for(int i=1;i<n;i++) for(int j=0;j<i;j++) if(nums[j]<nums[i]){
            if(dp[j]+1>dp[i]){dp[i]=dp[j]+1;cnt[i]=cnt[j];}
            else if(dp[j]+1==dp[i]) cnt[i]+=cnt[j];}
        for(int d:dp) maxLen=Math.max(maxLen,d);
        int t=0; for(int i=0;i<n;i++) if(dp[i]==maxLen) t+=cnt[i]; return t;
    }
}