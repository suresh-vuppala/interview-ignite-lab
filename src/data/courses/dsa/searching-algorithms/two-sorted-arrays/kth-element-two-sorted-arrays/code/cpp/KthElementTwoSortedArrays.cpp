#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Merge until Kth element — O(K) Time
// ============================================================
class Solution1 {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i=0, j=0, count=0;
        while(i<(int)a.size()&&j<(int)b.size()) {
            int val = (a[i]<=b[j]) ? a[i++] : b[j++];
            if(++count==k) return val;
        }
        while(i<(int)a.size()) if(++count==k) return a[i]; else i++;
        while(j<(int)b.size()) if(++count==k) return b[j]; else j++;
        return -1;
    }
};

// ============================================================
// Solution 2: Binary search on partition — O(log(min(M,N))) Time
// ============================================================
class Solution2 {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        if(a.size()>b.size()) swap(a,b);
        int m=a.size(), n=b.size();
        int lo=max(0,k-n), hi=min(k,m);
        while(lo<=hi) {
            int i=lo+(hi-lo)/2, j=k-i;
            int left1=(i>0)?a[i-1]:INT_MIN, right1=(i<m)?a[i]:INT_MAX;
            int left2=(j>0)?b[j-1]:INT_MIN, right2=(j<n)?b[j]:INT_MAX;
            if(left1<=right2&&left2<=right1) return max(left1,left2);
            if(left1>right2) hi=i-1; else lo=i+1;
        }
        return -1;
    }
};
