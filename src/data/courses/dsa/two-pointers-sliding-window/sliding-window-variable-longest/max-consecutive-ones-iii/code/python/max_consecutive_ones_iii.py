# ============================================================
# Max Consecutive Ones III
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def longestOnes(self, nums: List[int], k: int) -> int:
        max_len = 0
        for i in range(len(nums)):
            zeros = 0
            for j in range(i, len(nums)):
                if nums[j] == 0: zeros += 1
                if zeros > k: break
                max_len = max(max_len, j - i + 1)
        return max_len

# ============================================================
# Solution 2: Sliding Window (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left = zeros = max_len = 0

        for right in range(len(nums)):
            if nums[right] == 0:
                zeros += 1

            while zeros > k:
                if nums[left] == 0:
                    zeros -= 1
                left += 1

            max_len = max(max_len, right - left + 1)

        return max_len
