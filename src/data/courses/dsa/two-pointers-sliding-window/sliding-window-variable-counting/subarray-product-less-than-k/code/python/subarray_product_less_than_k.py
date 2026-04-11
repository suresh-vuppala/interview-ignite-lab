# ============================================================
# Subarray Product Less Than K
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        count = 0
        for i in range(len(nums)):
            prod = 1
            for j in range(i, len(nums)):
                prod *= nums[j]
                if prod >= k: break
                count += 1
        return count

# ============================================================
# Solution 2: Sliding Window (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1: return 0

        product = 1
        left = count = 0

        for right in range(len(nums)):
            product *= nums[right]

            while product >= k:
                product //= nums[left]
                left += 1

            # All subarrays ending at right: [left..right], [left+1..right], ...
            count += right - left + 1

        return count
