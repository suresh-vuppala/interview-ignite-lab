#include <vector>
#include <algorithm>
using namespace std;
class Solution{public:int maxProduct(vector<int>&nums){int maxP=nums[0],curMax=nums[0],curMin=nums[0];for(int i=1;i<nums.size();i++){if(nums[i]<0)swap(curMax,curMin);curMax=max(nums[i],curMax*nums[i]);curMin=min(nums[i],curMin*nums[i]);maxP=max(maxP,curMax);}return maxP;}};