#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all submatrices — O(M²*N²)
// ============================================================
class Solution1 {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), res=INT_MIN;
        for(int r1=0;r1<m;r1++) for(int c1=0;c1<n;c1++)
            for(int r2=r1;r2<m;r2++) for(int c2=c1;c2<n;c2++) {
                int sum=0;
                for(int i=r1;i<=r2;i++) for(int j=c1;j<=c2;j++) sum+=matrix[i][j];
                res=max(res,sum);
            }
        return res;
    }
};

// ============================================================
// Solution 2: Fix columns + Kadane's — O(M*N²) Time
// ============================================================
class Solution2 {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), res=INT_MIN;
        for(int l=0;l<n;l++) {
            vector<int> rowSum(m,0);
            for(int r=l;r<n;r++) {
                for(int i=0;i<m;i++) rowSum[i]+=matrix[i][r];
                // Kadane's on rowSum
                int cur=0, best=INT_MIN;
                for(int x:rowSum) { cur=max(x,cur+x); best=max(best,cur); }
                res=max(res,best);
            }
        }
        return res;
    }
};
