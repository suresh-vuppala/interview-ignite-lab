class Solution:
    def findNumberOfLIS(self, nums) -> int:
        n=len(nums); dp=[1]*n; cnt=[1]*n
        for i in range(1,n):
            for j in range(i):
                if nums[j]<nums[i]:
                    if dp[j]+1>dp[i]: dp[i]=dp[j]+1; cnt[i]=cnt[j]
                    elif dp[j]+1==dp[i]: cnt[i]+=cnt[j]
        max_len=max(dp)
        return sum(cnt[i] for i in range(n) if dp[i]==max_len)
