# ============================================================
# Remove Element
# ============================================================

from typing import List

# ============================================================
# Solution 1: Fast/Slow — Copy Non-Val Forward
# Time: O(N) | Space: O(1)
# ============================================================
class Solution1:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = 0
        for num in nums:
            if num != val:
                nums[j] = num
                j += 1
        return j

# ============================================================
# Solution 2: Swap with End — Fewer Writes
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        i = 0

        while i < n:
            if nums[i] == val:
                nums[i] = nums[n - 1]  # Replace with last
                n -= 1                   # Shrink
            else:
                i += 1

        return n
