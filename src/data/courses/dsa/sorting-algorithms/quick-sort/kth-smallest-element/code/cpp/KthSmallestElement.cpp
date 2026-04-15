#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Sort then index — O(N log N) Time
// ============================================================
class Solution1 {
public:
    int kthSmallest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};

// ============================================================
// Solution 2: Quickselect (Hoare's) — O(N) average, O(N²) worst
// ============================================================
class Solution2 {
    int partition(vector<int>& a, int lo, int hi) {
        int pivot=a[lo+(hi-lo)/2], i=lo, j=hi;
        while(i<=j){while(a[i]<pivot)i++;while(a[j]>pivot)j--;if(i<=j)swap(a[i++],a[j--]);}
        return i;
    }
public:
    int kthSmallest(vector<int>& nums, int k) {
        int lo=0, hi=nums.size()-1; k--; // 0-indexed
        while(lo<hi){
            int p=partition(nums,lo,hi);
            if(k<p) hi=p-1; else lo=p;
        }
        return nums[k];
    }
};
