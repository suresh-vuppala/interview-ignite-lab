# ============================================================
# Max Sum Subarray Not Greater Than M
# ============================================================

from typing import List
from sortedcontainers import SortedList

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def maxSumNotGreater(self, nums: List[int], M: int) -> int:
        max_sum = float('-inf')
        for i in range(len(nums)):
            total = 0
            for j in range(i, len(nums)):
                total += nums[j]
                if total <= M:
                    max_sum = max(max_sum, total)
        return max_sum

# ============================================================
# Solution 2: Prefix Sum + SortedList (Optimal)
# Time: O(N log N) | Space: O(N)
# ============================================================
class Solution2:
    def maxSumNotGreater(self, nums: List[int], M: int) -> int:
        from bisect import bisect_left

        prefix_list = SortedList([0])  # Need sorted container
        prefix = 0
        max_sum = float('-inf')

        for num in nums:
            prefix += num

            # Find smallest prefix_val >= prefix - M
            idx = prefix_list.bisect_left(prefix - M)

            if idx < len(prefix_list):
                val = prefix_list[idx]
                max_sum = max(max_sum, prefix - val)

            prefix_list.add(prefix)

        return max_sum
