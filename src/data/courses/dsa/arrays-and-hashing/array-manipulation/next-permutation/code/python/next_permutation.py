# ============================================================
# Next Permutation
# ============================================================

from typing import List

# ============================================================
# Solution: Three-Step Algorithm (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        i = n - 2

        # Step 1: Find rightmost dip (nums[i] < nums[i+1])
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        if i >= 0:
            # Step 2: Find rightmost element > nums[i]
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1

            # Step 3: Swap
            nums[i], nums[j] = nums[j], nums[i]

        # Step 4: Reverse suffix [i+1:]
        nums[i + 1:] = reversed(nums[i + 1:])
