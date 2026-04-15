#include <vector>
using namespace std;
// ============================================================
// Solution 1: Linear scan both directions — O(N) Time
// ============================================================
class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) {
                if (first == -1) first = i;
                last = i;
            }
        }
        return {first, last};
    }
};

// ============================================================
// Solution 2: Two binary searches — O(log N) Time, O(1) Space
// ============================================================
class Solution2 {
    int findFirst(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1, ans=-1;
        while(lo<=hi) { int mid=lo+(hi-lo)/2; if(nums[mid]==target){ans=mid;hi=mid-1;}else if(nums[mid]<target)lo=mid+1;else hi=mid-1; }
        return ans;
    }
    int findLast(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1, ans=-1;
        while(lo<=hi) { int mid=lo+(hi-lo)/2; if(nums[mid]==target){ans=mid;lo=mid+1;}else if(nums[mid]<target)lo=mid+1;else hi=mid-1; }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};
