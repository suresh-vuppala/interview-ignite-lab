#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // O(N²) DP
    int lengthOfLIS_DP(vector<int>& nums) {
        int n=nums.size(); vector<int> dp(n, 1);
        for (int i=1;i<n;i++) for (int j=0;j<i;j++)
            if (nums[j]<nums[i]) dp[i]=max(dp[i],dp[j]+1);
        return *max_element(dp.begin(),dp.end());
    }

    // O(N log N) Patience sorting
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) tails.push_back(num);
            else *it = num; // Replace with smaller tail
        }
        return tails.size();
    }
};
