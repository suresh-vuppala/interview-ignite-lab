# ============================================================
# Sort Colors (Dutch National Flag)
# ============================================================

from typing import List

# ============================================================
# Solution 1: Counting Sort — Two Pass
# Time: O(N) | Space: O(1)
# ============================================================
class Solution1:
    def sortColors(self, nums: List[int]) -> None:
        count = [nums.count(0), nums.count(1), nums.count(2)]
        idx = 0
        for color in range(3):
            for _ in range(count[color]):
                nums[idx] = color
                idx += 1

# ============================================================
# Solution 2: Dutch National Flag — Single Pass (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def sortColors(self, nums: List[int]) -> None:
        lo, mid, hi = 0, 0, len(nums) - 1

        while mid <= hi:
            if nums[mid] == 0:
                nums[lo], nums[mid] = nums[mid], nums[lo]
                lo += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:  # nums[mid] == 2
                nums[mid], nums[hi] = nums[hi], nums[mid]
                hi -= 1
                # Don't advance mid — swapped element is unknown
