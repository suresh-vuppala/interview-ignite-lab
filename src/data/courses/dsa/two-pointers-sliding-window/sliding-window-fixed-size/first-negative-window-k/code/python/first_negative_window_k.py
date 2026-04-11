# ============================================================
# First Negative in Every Window of Size K
# ============================================================

from typing import List
from collections import deque

# ============================================================
# Solution 1: Brute Force
# Time: O(N×K) | Space: O(1)
# ============================================================
class Solution1:
    def firstNegative(self, nums: List[int], k: int) -> List[int]:
        result = []
        for i in range(len(nums) - k + 1):
            found = 0
            for j in range(i, i + k):
                if nums[j] < 0:
                    found = nums[j]
                    break
            result.append(found)
        return result

# ============================================================
# Solution 2: Deque of Negative Indices (Optimal)
# Time: O(N) | Space: O(K)
# ============================================================
class Solution2:
    def firstNegative(self, nums: List[int], k: int) -> List[int]:
        neg_idx = deque()  # Indices of negative numbers
        result = []

        for i in range(len(nums)):
            if nums[i] < 0:
                neg_idx.append(i)

            if i >= k - 1:
                # Remove expired indices
                while neg_idx and neg_idx[0] < i - k + 1:
                    neg_idx.popleft()

                # Front = first negative in window
                result.append(nums[neg_idx[0]] if neg_idx else 0)

        return result
