# ============================================================
# 3Sum
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — All Triplets
# Time: O(N³) | Space: O(1)
# ============================================================
class Solution1:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = set()
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                for k in range(j + 1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        result.add((nums[i], nums[j], nums[k]))
        return [list(t) for t in result]

# ============================================================
# Solution 2: Sort + Two Pointers (Optimal)
# Time: O(N²) | Space: O(1) extra
# ============================================================
class Solution2:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []

        for i in range(len(nums) - 2):
            # Skip duplicate first element
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            # Early exit: smallest positive → no triplet
            if nums[i] > 0:
                break

            left, right = i + 1, len(nums) - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                if total == 0:
                    result.append([nums[i], nums[left], nums[right]])
                    # Skip duplicates
                    while left < right and nums[left] == nums[left + 1]: left += 1
                    while left < right and nums[right] == nums[right - 1]: right -= 1
                    left += 1; right -= 1
                elif total < 0:
                    left += 1
                else:
                    right -= 1

        return result
