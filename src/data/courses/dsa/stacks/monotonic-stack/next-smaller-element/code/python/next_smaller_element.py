# ============================================================
# Next Smaller Element
# ============================================================

from typing import List

class Solution1:
    def nextSmaller(self, nums: List[int]) -> List[int]:
        result = [-1] * len(nums)
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[j] < nums[i]: result[i] = nums[j]; break
        return result

class Solution2:
    def nextSmaller(self, nums: List[int]) -> List[int]:
        result = [-1] * len(nums)
        stack = []
        for i in range(len(nums)):
            while stack and nums[i] < nums[stack[-1]]:
                result[stack.pop()] = nums[i]
            stack.append(i)
        return result
