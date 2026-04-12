#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestBitonic(vector<int>& nums) {
        int n=nums.size(); vector<int> inc(n,1),dec(n,1);
        for(int i=1;i<n;i++) for(int j=0;j<i;j++) if(nums[j]<nums[i]) inc[i]=max(inc[i],inc[j]+1);
        for(int i=n-2;i>=0;i--) for(int j=n-1;j>i;j--) if(nums[j]<nums[i]) dec[i]=max(dec[i],dec[j]+1);
        int maxLen=0; for(int i=0;i<n;i++) maxLen=max(maxLen,inc[i]+dec[i]-1);
        return maxLen;
    }
};
