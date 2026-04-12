#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(),maxSum=INT_MIN;
        for(int l=0;l<n;l++){
            vector<int> rowSum(m,0);
            for(int r=l;r<n;r++){
                for(int i=0;i<m;i++) rowSum[i]+=mat[i][r];
                // Kadane's on rowSum
                int curr=0,best=INT_MIN;
                for(int s:rowSum){curr=max(s,curr+s);best=max(best,curr);}
                maxSum=max(maxSum,best);
            }
        }
        return maxSum;
    }
};