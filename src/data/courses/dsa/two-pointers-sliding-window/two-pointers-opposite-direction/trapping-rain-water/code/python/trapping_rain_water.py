# ============================================================
# Trapping Rain Water
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force — Per-Position Scan
# Time: O(N²) | Space: O(1)
# ============================================================
class Solution1:
    def trap(self, height: List[int]) -> int:
        water = 0
        for i in range(1, len(height) - 1):
            max_left = max(height[:i + 1])
            max_right = max(height[i:])
            water += min(max_left, max_right) - height[i]
        return water

# ============================================================
# Solution 2: Prefix Max Arrays
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left_max, right_max = [0] * n, [0] * n

        left_max[0] = height[0]
        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], height[i])

        right_max[-1] = height[-1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], height[i])

        return sum(
            min(left_max[i], right_max[i]) - height[i]
            for i in range(n)
        )

# ============================================================
# Solution 3: Two Pointers (Optimal)
# Time: O(N) | Space: O(1)
# ============================================================
class Solution3:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        max_left = max_right = water = 0

        while left < right:
            if height[left] < height[right]:
                # Left is shorter — process left
                if height[left] >= max_left:
                    max_left = height[left]
                else:
                    water += max_left - height[left]
                left += 1
            else:
                # Right is shorter — process right
                if height[right] >= max_right:
                    max_right = height[right]
                else:
                    water += max_right - height[right]
                right -= 1

        return water
