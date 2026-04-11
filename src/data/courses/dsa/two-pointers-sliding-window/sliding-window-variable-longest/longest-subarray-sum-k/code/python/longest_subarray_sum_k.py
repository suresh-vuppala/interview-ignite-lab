# ============================================================
# Longest Subarray with Sum K
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def longestSubarray(self, nums: List[int], k: int) -> int:
        max_len = 0
        for i in range(len(nums)):
            total = 0
            for j in range(i, len(nums)):
                total += nums[j]
                if total == k:
                    max_len = max(max_len, j - i + 1)
        return max_len

# ============================================================
# Solution 2: Prefix Sum + Hash Map (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def longestSubarray(self, nums: List[int], k: int) -> int:
        first_occurrence = {0: -1}  # prefix_sum → first index
        prefix_sum = 0
        max_len = 0

        for j in range(len(nums)):
            prefix_sum += nums[j]

            # Check if complement prefix sum was seen
            if prefix_sum - k in first_occurrence:
                max_len = max(max_len, j - first_occurrence[prefix_sum - k])

            # Store first occurrence only (for max length)
            if prefix_sum not in first_occurrence:
                first_occurrence[prefix_sum] = j

        return max_len
