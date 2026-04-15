#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Merge then find median — O(M+N) Time+Space
// ============================================================
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i=0, j=0;
        while(i<(int)nums1.size()&&j<(int)nums2.size()) {
            if(nums1[i]<=nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        while(i<(int)nums1.size()) merged.push_back(nums1[i++]);
        while(j<(int)nums2.size()) merged.push_back(nums2[j++]);
        int n=merged.size();
        return n%2 ? merged[n/2] : (merged[n/2-1]+merged[n/2])/2.0;
    }
};

// ============================================================
// Solution 2: Binary search on partition — O(log(min(M,N))) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) swap(nums1,nums2);
        int m=nums1.size(), n=nums2.size();
        int lo=0, hi=m, half=(m+n+1)/2;
        while(lo<=hi) {
            int i=lo+(hi-lo)/2, j=half-i;
            int left1=(i>0)?nums1[i-1]:INT_MIN, right1=(i<m)?nums1[i]:INT_MAX;
            int left2=(j>0)?nums2[j-1]:INT_MIN, right2=(j<n)?nums2[j]:INT_MAX;
            if(left1<=right2&&left2<=right1) {
                if((m+n)%2) return max(left1,left2);
                return (max(left1,left2)+min(right1,right2))/2.0;
            }
            if(left1>right2) hi=i-1; else lo=i+1;
        }
        return 0;
    }
};
