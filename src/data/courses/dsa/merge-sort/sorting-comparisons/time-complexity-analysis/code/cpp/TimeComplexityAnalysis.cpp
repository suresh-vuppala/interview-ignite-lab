#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: O(N²) example — Bubble Sort
// ============================================================
class Solution1 {
public:
    void bubbleSort(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)         // N iterations
            for(int j=0;j<n-i-1;j++) // N-i-1 comparisons
                if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]);
        // Total: N*(N-1)/2 = O(N²) comparisons
        // Best case with early exit: O(N)
    }
};

// ============================================================
// Solution 2: O(N log N) example — Merge Sort
// ============================================================
class Solution2 {
    void merge(vector<int>&a,int l,int m,int r){
        vector<int> tmp;int i=l,j=m+1;
        while(i<=m&&j<=r) tmp.push_back(a[i]<=a[j]?a[i++]:a[j++]);
        while(i<=m) tmp.push_back(a[i++]);
        while(j<=r) tmp.push_back(a[j++]);
        for(int k=0;k<(int)tmp.size();k++) a[l+k]=tmp[k];
    }
    void sort_(vector<int>&a,int l,int r){
        if(l>=r)return;
        int m=l+(r-l)/2;     // T(N) = 2*T(N/2) + O(N)
        sort_(a,l,m);         // Left half
        sort_(a,m+1,r);       // Right half
        merge(a,l,m,r);       // Merge: O(N)
    }
public:
    void mergeSort(vector<int>& nums){if(!nums.empty())sort_(nums,0,nums.size()-1);}
    // By Master Theorem: T(N) = O(N log N) always
};
