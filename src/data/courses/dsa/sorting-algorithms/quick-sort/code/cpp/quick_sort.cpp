#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Lomuto partition (last element pivot) — O(N²) worst case
// ============================================================
class Solution1 {
    int lomuto(vector<int>& a, int lo, int hi) {
        int pivot=a[hi], i=lo-1;
        for(int j=lo;j<hi;j++) if(a[j]<=pivot) swap(a[++i],a[j]);
        swap(a[i+1],a[hi]); return i+1;
    }
    void qsort(vector<int>& a, int lo, int hi) {
        if(lo>=hi) return;
        int p=lomuto(a,lo,hi);
        qsort(a,lo,p-1); qsort(a,p+1,hi);
    }
public:
    void quickSort(vector<int>& nums) { if(!nums.empty()) qsort(nums,0,nums.size()-1); }
};

// ============================================================
// Solution 2: Hoare partition (middle pivot) — fewer swaps, O(N log N) avg
// ============================================================
class Solution2 {
    int hoare(vector<int>& a, int lo, int hi) {
        int pivot=a[lo+(hi-lo)/2], i=lo-1, j=hi+1;
        while(true){
            do i++; while(a[i]<pivot);
            do j--; while(a[j]>pivot);
            if(i>=j) return j;
            swap(a[i],a[j]);
        }
    }
    void qsort(vector<int>& a, int lo, int hi) {
        if(lo>=hi) return;
        int p=hoare(a,lo,hi);
        qsort(a,lo,p); qsort(a,p+1,hi);
    }
public:
    void quickSort(vector<int>& nums) { if(!nums.empty()) qsort(nums,0,nums.size()-1); }
};
