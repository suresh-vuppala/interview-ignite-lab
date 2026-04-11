# ============================================================
# Next Greater Element
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def nextGreaterElement(self, nums: List[int]) -> List[int]:
        result = [-1] * len(nums)
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[j] > nums[i]:
                    result[i] = nums[j]
                    break
        return result

# ============================================================
# Solution 2: Monotonic Stack (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def nextGreaterElement(self, nums: List[int]) -> List[int]:
        result = [-1] * len(nums)
        stack = []  # Indices — decreasing by value

        for i in range(len(nums)):
            # Pop all smaller — current is their NGE
            while stack and nums[i] > nums[stack[-1]]:
                result[stack.pop()] = nums[i]

            stack.append(i)

        return result
