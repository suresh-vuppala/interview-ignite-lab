# ============================================================
# Move Zeroes
# ============================================================

from typing import List

# ============================================================
# Solution 1: Two-Pass (Copy then Fill)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution1:
    def moveZeroes(self, nums: List[int]) -> None:
        j = 0
        for num in nums:
            if num != 0:
                nums[j] = num
                j += 1
        while j < len(nums):
            nums[j] = 0
            j += 1

# ============================================================
# Solution 2: Single-Pass Swap (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def moveZeroes(self, nums: List[int]) -> None:
        j = 0  # Next position for non-zero

        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
