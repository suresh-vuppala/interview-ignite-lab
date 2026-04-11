# ============================================================
# Subarrays with K Different Integers
# ============================================================

from typing import List
from collections import defaultdict

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(N)
# ============================================================
class Solution1:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        count = 0
        for i in range(len(nums)):
            freq = defaultdict(int)
            for j in range(i, len(nums)):
                freq[nums[j]] += 1
                if len(freq) == k: count += 1
                if len(freq) > k: break
        return count

# ============================================================
# Solution 2: At Most K Decomposition (Optimal)
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        def at_most_k(k):
            freq = defaultdict(int)
            left = count = 0
            for right in range(len(nums)):
                freq[nums[right]] += 1
                while len(freq) > k:
                    freq[nums[left]] -= 1
                    if freq[nums[left]] == 0: del freq[nums[left]]
                    left += 1
                count += right - left + 1
            return count

        # exactly(k) = atMost(k) - atMost(k-1)
        return at_most_k(k) - at_most_k(k - 1)
