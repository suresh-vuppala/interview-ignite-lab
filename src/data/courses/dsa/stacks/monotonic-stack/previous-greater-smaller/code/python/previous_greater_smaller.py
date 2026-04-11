# ============================================================
# Previous Greater and Previous Smaller
# ============================================================

from typing import List

class Solution:
    def previousGreater(self, nums: List[int]) -> List[int]:
        result = [-1] * len(nums)
        stack = []  # Decreasing
        for i in range(len(nums)):
            while stack and nums[stack[-1]] <= nums[i]: stack.pop()
            if stack: result[i] = nums[stack[-1]]
            stack.append(i)
        return result

    def previousSmaller(self, nums: List[int]) -> List[int]:
        result = [-1] * len(nums)
        stack = []  # Increasing
        for i in range(len(nums)):
            while stack and nums[stack[-1]] >= nums[i]: stack.pop()
            if stack: result[i] = nums[stack[-1]]
            stack.append(i)
        return result
