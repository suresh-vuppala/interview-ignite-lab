from collections import deque
class Solution:
    def maxSlidingWindow(self, nums, k):
        dq, result = deque(), []
        for i in range(len(nums)):
            while dq and dq[0] < i-k+1: dq.popleft()      # Remove expired
            while dq and nums[dq[-1]] <= nums[i]: dq.pop() # Remove smaller
            dq.append(i)
            if i >= k-1: result.append(nums[dq[0]])
        return result