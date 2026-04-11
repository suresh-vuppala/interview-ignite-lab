class Solution:
    def minAbsDifference(self, nums, goal):
        from bisect import bisect_left
        n=len(nums); h=n//2
        L=[sum(nums[i] for i in range(h) if m&(1<<i)) for m in range(1<<h)]
        R=sorted(sum(nums[h+i] for i in range(n-h) if m&(1<<i)) for m in range(1<<(n-h)))
        best=float('inf')
        for s in L:
            idx=bisect_left(R,goal-s)
            if idx<len(R): best=min(best,abs(s+R[idx]-goal))
            if idx>0: best=min(best,abs(s+R[idx-1]-goal))
        return best