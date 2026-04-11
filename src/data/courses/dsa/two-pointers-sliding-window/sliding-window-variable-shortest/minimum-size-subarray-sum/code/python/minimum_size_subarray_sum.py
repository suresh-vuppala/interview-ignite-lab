# ============================================================
# Minimum Size Subarray Sum
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_len = float('inf')
        for i in range(len(nums)):
            total = 0
            for j in range(i, len(nums)):
                total += nums[j]
                if total >= target:
                    min_len = min(min_len, j - i + 1)
                    break
        return 0 if min_len == float('inf') else min_len

# ============================================================
# Solution 2: Sliding Window (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left = total = 0
        min_len = float('inf')

        for right in range(len(nums)):
            total += nums[right]  # Expand

            while total >= target:  # Shrink while valid
                min_len = min(min_len, right - left + 1)
                total -= nums[left]
                left += 1

        return 0 if min_len == float('inf') else min_len
