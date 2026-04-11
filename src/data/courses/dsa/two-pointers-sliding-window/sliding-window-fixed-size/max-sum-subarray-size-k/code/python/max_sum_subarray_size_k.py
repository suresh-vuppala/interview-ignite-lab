# ============================================================
# Maximum Sum Subarray of Size K
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N×K) | Space: O(1)
# ============================================================
class Solution1:
    def maxSumSubarray(self, nums: List[int], k: int) -> int:
        max_sum = float('-inf')
        for i in range(len(nums) - k + 1):
            max_sum = max(max_sum, sum(nums[i:i+k]))
        return max_sum

# ============================================================
# Solution 2: Sliding Window — Running Max (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def maxSumSubarray(self, nums: List[int], k: int) -> int:
        window_sum = sum(nums[:k])
        max_sum = window_sum

        for i in range(k, len(nums)):
            window_sum += nums[i] - nums[i - k]
            max_sum = max(max_sum, window_sum)

        return max_sum
