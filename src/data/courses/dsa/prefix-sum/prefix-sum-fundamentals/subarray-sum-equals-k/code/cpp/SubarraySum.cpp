#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        //To consider subarray with starting index [0...i] nums[0...i] -> PS[i]-PS[0]
        int PS[n+1];
        //Prefix sum of zero elements is 0
        PS[0]=0;
        // Compute Prefix sum
        for(int i=1;i<n+1;i++)
        {
             PS[i]=PS[i-1]+nums[i-1];
        }
          // Counter of each prefix sum 
        unordered_map<int,int> mp;
        //To consider subarray Sum[0...i]
        mp[0]=1;
       int count=0;
        for(int end=1;end<n+1;end++){
            //subarray sum k is possible for current prefix sum if sum-k exists
            // Sum in range[start, end] ==K
            // PS[end]-PS[start-1] ==K => PS[start-1] = PS[end]-k;
            int sum = PS[end]-k;
            if(mp.find(sum)!=mp.end()) count+= mp[sum];
            mp[PS[end]]++; // update current prefix sum frequency/count
        }
        
       return count;
    }
};
