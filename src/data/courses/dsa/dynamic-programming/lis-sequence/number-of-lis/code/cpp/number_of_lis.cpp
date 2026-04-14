#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — find all subsequences, check LIS
// ============================================================
class Solution1 {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(), maxLen=0, count=0;
        vector<int> dp(n,1), cnt(n,1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) if(nums[j]<nums[i]) {
                if(dp[j]+1>dp[i]) { dp[i]=dp[j]+1; cnt[i]=cnt[j]; }
                else if(dp[j]+1==dp[i]) cnt[i]+=cnt[j];
            }
            if(dp[i]>maxLen) { maxLen=dp[i]; count=cnt[i]; }
            else if(dp[i]==maxLen) count+=cnt[i];
        }
        return count;
    }
};

// ============================================================
// Solution 2: DP — length + count arrays — O(N²) Time
// ============================================================
class Solution2 {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(), maxLen=0, res=0;
        vector<int> dp(n,1), cnt(n,1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<i;j++) if(nums[j]<nums[i]) {
                if(dp[j]+1>dp[i]) { dp[i]=dp[j]+1; cnt[i]=cnt[j]; }
                else if(dp[j]+1==dp[i]) cnt[i]+=cnt[j];
            }
            maxLen=max(maxLen,dp[i]);
        }
        for(int i=0;i<n;i++) if(dp[i]==maxLen) res+=cnt[i];
        return res;
    }
};
