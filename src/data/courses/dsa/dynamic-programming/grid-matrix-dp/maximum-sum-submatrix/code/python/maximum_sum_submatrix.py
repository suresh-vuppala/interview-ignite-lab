class Solution:
    def maxSumSubmatrix(self, mat):
        m,n=len(mat),len(mat[0]); max_sum=float('-inf')
        for l in range(n):
            row_sum=[0]*m
            for r in range(l,n):
                for i in range(m): row_sum[i]+=mat[i][r]
                curr=best=float('-inf')
                for s in row_sum: curr=max(s,curr+s); best=max(best,curr)
                max_sum=max(max_sum,best)
        return max_sum
