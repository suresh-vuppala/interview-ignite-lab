# ============================================================
# Find All Duplicates in Array
# ============================================================

from typing import List

# ============================================================
# Solution 1: Hash Set
# Time: O(N) | Space: O(N)
# ============================================================
class Solution1:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        seen, result = set(), []

        for num in nums:
            if num in seen:
                result.append(num)
            else:
                seen.add(num)

        return result

# ============================================================
# Solution 2: Index Marking — Negate to Flag (Optimal)
# Time: O(N) | Space: O(1) extra
# ============================================================
class Solution2:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result = []

        for num in nums:
            idx = abs(num) - 1

            if nums[idx] < 0:
                result.append(idx + 1)  # Already negated → duplicate
            else:
                nums[idx] = -nums[idx]  # Mark visited

        return result
