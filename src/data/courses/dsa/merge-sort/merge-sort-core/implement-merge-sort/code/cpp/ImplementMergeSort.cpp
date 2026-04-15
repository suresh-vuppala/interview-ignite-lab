#include <vector>
using namespace std;
// ============================================================
// Solution 1: Top-down recursive merge sort — O(N log N) Time, O(N) Space
// ============================================================
class Solution1 {
    void merge(vector<int>& a, int l, int m, int r) {
        vector<int> tmp(r-l+1);
        int i=l, j=m+1, k=0;
        while(i<=m && j<=r) tmp[k++] = a[i]<=a[j] ? a[i++] : a[j++];
        while(i<=m) tmp[k++]=a[i++];
        while(j<=r) tmp[k++]=a[j++];
        for(int x=0;x<k;x++) a[l+x]=tmp[x];
    }
    void sort(vector<int>& a, int l, int r) {
        if(l>=r) return;
        int m=l+(r-l)/2;
        sort(a,l,m); sort(a,m+1,r);
        merge(a,l,m,r);
    }
public:
    void mergeSort(vector<int>& nums) { if(!nums.empty()) sort(nums,0,nums.size()-1); }
};

// ============================================================
// Solution 2: Bottom-up iterative merge sort — O(N log N) Time, no recursion stack
// ============================================================
class Solution2 {
    void merge(vector<int>& a, int l, int m, int r) {
        vector<int> tmp(r-l+1);
        int i=l,j=m+1,k=0;
        while(i<=m&&j<=r) tmp[k++]=a[i]<=a[j]?a[i++]:a[j++];
        while(i<=m)tmp[k++]=a[i++]; while(j<=r)tmp[k++]=a[j++];
        for(int x=0;x<k;x++)a[l+x]=tmp[x];
    }
public:
    void mergeSort(vector<int>& nums) {
        int n=nums.size();
        for(int width=1; width<n; width*=2)
            for(int i=0; i<n; i+=2*width) {
                int mid=min(i+width-1,n-1), right=min(i+2*width-1,n-1);
                if(mid<right) merge(nums,i,mid,right);
            }
    }
};
