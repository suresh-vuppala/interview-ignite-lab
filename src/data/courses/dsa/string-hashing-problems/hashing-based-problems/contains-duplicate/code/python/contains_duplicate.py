# ============================================================
# Contains Duplicate
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — Check All Pairs
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def containsDuplicate(self, nums: List[int]) -> bool:

        # Compare every pair (i, j)
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if nums[i] == nums[j]:
                    return True

        return False

# ============================================================
# Solution 2: Sort + Adjacent Check
# Time: O(N log N) | Space: O(1)
# ============================================================
class Solution2:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return True

        return False

# ============================================================
# Solution 3: Hash Set — O(1) Lookup (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution3:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Pythonic: set removes duplicates — compare lengths
        return len(nums) != len(set(nums))
