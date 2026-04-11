# ============================================================
# Distinct Elements in Every Window of Size K
# ============================================================

from typing import List
from collections import defaultdict

# ============================================================
# Solution 1: Brute Force — Set per Window
# Time: O(N×K) | Space: O(K)
# ============================================================
class Solution1:
    def distinctInWindow(self, nums: List[int], k: int) -> List[int]:
        return [len(set(nums[i:i+k])) for i in range(len(nums) - k + 1)]

# ============================================================
# Solution 2: Sliding Window + Frequency Map (Optimal)
# Time: O(N) | Space: O(K)
# ============================================================
class Solution2:
    def distinctInWindow(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        result = []

        for i in range(len(nums)):
            freq[nums[i]] += 1          # Add entering

            if i >= k:                   # Remove leaving
                freq[nums[i - k]] -= 1
                if freq[nums[i - k]] == 0:
                    del freq[nums[i - k]]  # Delete key when count = 0

            if i >= k - 1:
                result.append(len(freq)) # Map size = distinct count

        return result
