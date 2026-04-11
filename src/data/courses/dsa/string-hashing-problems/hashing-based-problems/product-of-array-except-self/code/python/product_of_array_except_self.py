# ============================================================
# Product of Array Except Self
# ============================================================

from typing import List

# ============================================================
# Solution 1: Brute Force
# Time: O(N²) | Space: O(1) extra
# ============================================================
class Solution1:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n

        # For each position, multiply all other elements
        for i in range(n):
            for j in range(n):
                if i != j:
                    result[i] *= nums[j]

        return result

# ============================================================
# Solution 2: Prefix + Suffix Arrays
# Time: O(N) | Space: O(N)
# ============================================================
class Solution2:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix, suffix = [1] * n, [1] * n

        for i in range(1, n):
            prefix[i] = prefix[i - 1] * nums[i - 1]
        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] * nums[i + 1]

        return [prefix[i] * suffix[i] for i in range(n)]

# ============================================================
# Solution 3: Two-Pass with Running Variable (Optimal)
# Time: O(N) | Space: O(1) extra
# ============================================================
class Solution3:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n

        # Pass 1: left prefix products
        left = 1
        for i in range(n):
            result[i] = left
            left *= nums[i]

        # Pass 2: multiply by right suffix products
        right = 1
        for i in range(n - 1, -1, -1):
            result[i] *= right
            right *= nums[i]

        return result
