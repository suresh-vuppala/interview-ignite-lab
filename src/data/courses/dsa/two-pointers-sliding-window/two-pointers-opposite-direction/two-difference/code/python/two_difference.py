# ============================================================
# Two Difference
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — All Pairs
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def findPair(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if abs(nums[i] - nums[j]) == k:
                    return True
        return False

# ============================================================
# Solution 2: Sort + Two Pointers (Optimal)
# Time: O(N log N) | Space: O(1)
# ============================================================
class Solution2:
    def findPair(self, nums: List[int], k: int) -> bool:
        nums.sort()
        i, j = 0, 1

        while i < len(nums) and j < len(nums):
            if i == j:
                j += 1
                continue

            diff = nums[j] - nums[i]

            if diff == k: return True
            if diff < k: j += 1     # Need larger diff
            else: i += 1             # Need smaller diff

        return False
