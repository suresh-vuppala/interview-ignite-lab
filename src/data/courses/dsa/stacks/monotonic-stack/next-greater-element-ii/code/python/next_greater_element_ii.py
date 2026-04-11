# ============================================================
# Next Greater Element II (Circular)
# ============================================================

from typing import List

class Solution1:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [-1] * n
        for i in range(n):
            for j in range(1, n):
                if nums[(i+j) % n] > nums[i]:
                    result[i] = nums[(i+j) % n]; break
        return result

class Solution2:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [-1] * n
        stack = []
        for i in range(2 * n):
            while stack and nums[i % n] > nums[stack[-1]]:
                result[stack.pop()] = nums[i % n]
            if i < n: stack.append(i)
        return result
