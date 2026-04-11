# ============================================================
# Two Sum
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        # Try every possible pair (i, j) where i < j
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):

                # Check if this pair sums to target
                if nums[i] + nums[j] == target:
                    return [i, j]

        return []  # No solution found

# ============================================================
# Solution 2: Hash Map — One Pass (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Dict stores: value → index (for O(1) complement lookup)
        seen = {}

        for i, num in enumerate(nums):
            # For current number, compute what we need
            complement = target - num

            # Check if complement was seen earlier
            if complement in seen:
                return [seen[complement], i]  # Found! Return both indices

            # Store current number for future lookups
            seen[num] = i

        return []
