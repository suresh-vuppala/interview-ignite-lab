# ============================================================
# Longest Consecutive Sequence
# ============================================================

from typing import List

# ============================================================
# Solution 1: Sort + Linear Scan
# Time: O(N log N) | Space: O(1)
# ============================================================
class Solution1:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        nums.sort()
        max_len = cur_len = 1

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                continue              # Skip duplicates
            if nums[i] == nums[i - 1] + 1:
                cur_len += 1          # Extend streak
            else:
                cur_len = 1           # Reset streak
            max_len = max(max_len, cur_len)

        return max_len

# ============================================================
# Solution 2: Hash Set — Count from Beginnings (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_len = 0

        for num in num_set:
            # Only start from sequence beginnings (num-1 not in set)
            if num - 1 not in num_set:
                current, length = num, 1

                # Count forward
                while current + 1 in num_set:
                    current += 1
                    length += 1

                max_len = max(max_len, length)

        return max_len
