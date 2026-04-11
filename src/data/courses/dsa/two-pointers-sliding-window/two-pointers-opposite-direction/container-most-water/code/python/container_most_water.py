# ============================================================
# Container With Most Water
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — All Pairs
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        for i in range(len(height) - 1):
            for j in range(i + 1, len(height)):
                area = min(height[i], height[j]) * (j - i)
                max_area = max(max_area, area)
        return max_area

# ============================================================
# Solution 2: Two Pointers — Move Shorter Side (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution2:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_area = 0

        while left < right:
            area = min(height[left], height[right]) * (right - left)
            max_area = max(max_area, area)

            # Move the shorter side inward
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area
