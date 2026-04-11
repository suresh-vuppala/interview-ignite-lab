# ============================================================
# Remove Duplicates from Sorted Array
# ============================================================

from typing import List

# ============================================================
# Solution 1: Extra Array
# Time: O(N) | Space: O(N)
# ============================================================
class Solution1:
    def removeDuplicates(self, nums: List[int]) -> int:
        unique = [nums[0]]

        for i in range(1, len(nums)):
            if nums[i] != unique[-1]:
                unique.append(nums[i])

        for i in range(len(unique)):
            nums[i] = unique[i]
        return len(unique)

# ============================================================
# Solution 2: Slow/Fast Two Pointers (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def removeDuplicates(self, nums: List[int]) -> int:
        j = 0  # Last unique position

        for i in range(1, len(nums)):
            if nums[i] != nums[j]:
                j += 1
                nums[j] = nums[i]

        return j + 1
