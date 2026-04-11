# ============================================================
# Two Sum II — Input Array Is Sorted
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — All Pairs
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers) - 1):
            for j in range(i + 1, len(numbers)):
                if numbers[i] + numbers[j] == target:
                    return [i + 1, j + 1]

# ============================================================
# Solution 2: Two Pointers — Converge from Ends (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1

        while left < right:
            current_sum = numbers[left] + numbers[right]

            if current_sum == target:
                return [left + 1, right + 1]  # 1-indexed
            elif current_sum < target:
                left += 1    # Need larger sum
            else:
                right -= 1   # Need smaller sum
