#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Merge Sort — O(N log N) guaranteed, O(N) extra space, stable
// ============================================================
class Solution1 {
    void merge(vector<int>& a,int l,int m,int r){
        vector<int> tmp;int i=l,j=m+1;
        while(i<=m&&j<=r)tmp.push_back(a[i]<=a[j]?a[i++]:a[j++]);
        while(i<=m)tmp.push_back(a[i++]);while(j<=r)tmp.push_back(a[j++]);
        for(int k=0;k<(int)tmp.size();k++)a[l+k]=tmp[k];
    }
    void sort_(vector<int>&a,int l,int r){if(l>=r)return;int m=l+(r-l)/2;sort_(a,l,m);sort_(a,m+1,r);merge(a,l,m,r);}
public:
    void mergeSort(vector<int>& nums){if(!nums.empty())sort_(nums,0,nums.size()-1);}
};

// ============================================================
// Solution 2: Quick Sort — O(N log N) avg, O(1) extra space, unstable
// ============================================================
class Solution2 {
    int partition(vector<int>&a,int lo,int hi){
        int pivot=a[lo+(hi-lo)/2],i=lo-1,j=hi+1;
        while(true){do i++;while(a[i]<pivot);do j--;while(a[j]>pivot);if(i>=j)return j;swap(a[i],a[j]);}
    }
    void qsort(vector<int>&a,int lo,int hi){if(lo>=hi)return;int p=partition(a,lo,hi);qsort(a,lo,p);qsort(a,p+1,hi);}
public:
    void quickSort(vector<int>& nums){if(!nums.empty())qsort(nums,0,nums.size()-1);}
};
