# ============================================================
# Squares of a Sorted Array
# ============================================================

from typing import List

# ============================================================
# Solution 1: Square + Sort
# Time: O(N log N) | Space: O(1)
# ============================================================
class Solution1:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted(x * x for x in nums)

# ============================================================
# Solution 2: Two Pointers from Ends (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        left, right = 0, n - 1
        pos = n - 1  # Fill from back

        while left <= right:
            l_sq = nums[left] ** 2
            r_sq = nums[right] ** 2

            if l_sq > r_sq:
                result[pos] = l_sq
                left += 1
            else:
                result[pos] = r_sq
                right -= 1
            pos -= 1

        return result
