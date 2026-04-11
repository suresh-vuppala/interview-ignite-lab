# ============================================================
# Sliding Window Maximum
# ============================================================

from typing import List
from collections import deque

# ============================================================
# Solution 1: Brute Force
# Time: O(N×K) | Space: O(1)
# ============================================================
class Solution1:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        return [max(nums[i:i+k]) for i in range(len(nums) - k + 1)]

# ============================================================
# Solution 2: Monotonic Decreasing Deque (Optimal)
# Time: O(N) | Space: O(K)
# ============================================================
class Solution2:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()  # Stores indices; front = current max
        result = []

        for i in range(len(nums)):
            # Remove expired indices from front
            while dq and dq[0] < i - k + 1:
                dq.popleft()

            # Remove smaller elements from back
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()

            dq.append(i)

            # Window is full — front is the max
            if i >= k - 1:
                result.append(nums[dq[0]])

        return result
