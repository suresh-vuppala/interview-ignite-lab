# ============================================================
# Majority Element
# ============================================================

from typing import List
from collections import Counter

# ============================================================
# Solution 1: Hash Map — Count Frequencies
# Time: O(N) | Space: O(N)
# ============================================================
class Solution1:
    def majorityElement(self, nums: List[int]) -> int:
        freq = Counter(nums)
        return max(freq, key=freq.get)

# ============================================================
# Solution 2: Sort + Middle Element
# Time: O(N log N) | Space: O(1)
# ============================================================
class Solution2:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        return nums[len(nums) // 2]

# ============================================================
# Solution 3: Boyer-Moore Voting Algorithm (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution3:
    def majorityElement(self, nums: List[int]) -> int:
        candidate, count = nums[0], 1

        for i in range(1, len(nums)):
            if count == 0:
                candidate, count = nums[i], 1
            elif nums[i] == candidate:
                count += 1
            else:
                count -= 1

        return candidate
