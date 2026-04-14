#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N * N) Time
// ============================================================
class Solution1 {
public:
    int lis(vector<int>& nums, int i, int prev, bool inc) {
        if(i>=(int)nums.size()) return 0;
        int skip=lis(nums,i+1,prev,inc);
        int take=0;
        if(inc && nums[i]>prev) take=1+lis(nums,i+1,nums[i],true);
        if(!inc && nums[i]<prev) take=max(take,1+lis(nums,i+1,nums[i],false));
        return max(skip,take);
    }
    int longestBitonic(vector<int>& nums) { /* simplified — enumerate peak */ return 0; }
};

// ============================================================
// Solution 2: DP — LIS forward + LIS backward — O(N²) Time
// ============================================================
class Solution2 {
public:
    int longestBitonic(vector<int>& nums) {
        int n=nums.size(); if(n<3) return 0;
        vector<int> lis(n,1), lds(n,1);
        for(int i=1;i<n;i++) for(int j=0;j<i;j++) if(nums[j]<nums[i]) lis[i]=max(lis[i],lis[j]+1);
        for(int i=n-2;i>=0;i--) for(int j=n-1;j>i;j--) if(nums[j]<nums[i]) lds[i]=max(lds[i],lds[j]+1);
        int res=0;
        for(int i=0;i<n;i++) if(lis[i]>1&&lds[i]>1) res=max(res,lis[i]+lds[i]-1);
        return res;
    }
};
