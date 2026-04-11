# ============================================================
# Subarray Sum — Fixed Size K
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — Recompute Each Window
# Time: O(N×K) | Space: O(1)
# ============================================================
class Solution1:
    def hasSubarraySum(self, nums: List[int], k: int, target: int) -> bool:
        for i in range(len(nums) - k + 1):
            if sum(nums[i:i+k]) == target:
                return True
        return False

# ============================================================
# Solution 2: Sliding Window — Running Sum (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def hasSubarraySum(self, nums: List[int], k: int, target: int) -> bool:
        # First window
        window_sum = sum(nums[:k])
        if window_sum == target:
            return True

        # Slide: subtract leaving, add entering
        for i in range(k, len(nums)):
            window_sum += nums[i] - nums[i - k]
            if window_sum == target:
                return True

        return False
