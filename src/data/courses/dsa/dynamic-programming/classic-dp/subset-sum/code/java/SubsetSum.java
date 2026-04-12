class Solution {
    public boolean subsetSum(int[] nums, int target) {
        boolean[] dp=new boolean[target+1]; dp[0]=true;
        for (int n:nums) for (int j=target;j>=n;j--) dp[j]=dp[j]||dp[j-n];
        return dp[target];
    }
}