#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — count all (i,j) where i<j and a[i]>a[j] — O(N²)
// ============================================================
class Solution1 {
public:
    long long countInversions(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (nums[i] > nums[j]) count++;
        return count;
    }
};

// ============================================================
// Solution 2: Modified Merge Sort — count during merge — O(N log N)
// ============================================================
class Solution2 {
    long long mergeCount(vector<int>& a, int l, int m, int r) {
        vector<int> tmp; int i=l, j=m+1; long long inv=0;
        while(i<=m && j<=r) {
            if(a[i]<=a[j]) tmp.push_back(a[i++]);
            else { tmp.push_back(a[j++]); inv += (m-i+1); } // All remaining left > a[j]
        }
        while(i<=m) tmp.push_back(a[i++]);
        while(j<=r) tmp.push_back(a[j++]);
        for(int k=0;k<(int)tmp.size();k++) a[l+k]=tmp[k];
        return inv;
    }
    long long sortCount(vector<int>& a, int l, int r) {
        if(l>=r) return 0;
        int m=l+(r-l)/2;
        return sortCount(a,l,m) + sortCount(a,m+1,r) + mergeCount(a,l,m,r);
    }
public:
    long long countInversions(vector<int>& nums) { return sortCount(nums,0,nums.size()-1); }
};
