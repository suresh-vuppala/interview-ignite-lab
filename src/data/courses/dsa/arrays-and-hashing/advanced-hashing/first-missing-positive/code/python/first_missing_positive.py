# ============================================================
# First Missing Positive
# ============================================================

from typing import List

# ============================================================
# Solution 1: Hash Set
# Time: O(N) | Space: O(N)
# ============================================================
class Solution1:
    def firstMissingPositive(self, nums: List[int]) -> int:
        num_set = set(nums)

        # Check 1, 2, 3, ... until missing found
        for i in range(1, len(nums) + 2):
            if i not in num_set:
                return i

# ============================================================
# Solution 2: Cyclic Sort — Array as Hash Map (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)

        # Cyclic sort: place value v at index v-1
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                # Swap nums[i] with nums[nums[i]-1]
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        # Find first mismatch
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        return n + 1  # All 1..N present
