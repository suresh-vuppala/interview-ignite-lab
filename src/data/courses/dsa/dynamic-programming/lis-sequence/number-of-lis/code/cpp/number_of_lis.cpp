#include <vector>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxLen=1;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=1;i<n;i++) for(int j=0;j<i;j++) if(nums[j]<nums[i]){
            if(dp[j]+1>dp[i]){dp[i]=dp[j]+1;cnt[i]=cnt[j];}
            else if(dp[j]+1==dp[i]) cnt[i]+=cnt[j];
        }
        for(int d:dp) maxLen=max(maxLen,d);
        int total=0; for(int i=0;i<n;i++) if(dp[i]==maxLen) total+=cnt[i];
        return total;
    }
};
