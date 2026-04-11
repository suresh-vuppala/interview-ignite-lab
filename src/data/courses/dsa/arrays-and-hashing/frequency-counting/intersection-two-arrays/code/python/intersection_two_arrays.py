# ============================================================
# Intersection of Two Arrays II
# ============================================================

from typing import List
from collections import Counter

# ============================================================
# Solution 1: Sort + Two Pointers
# Time: O(N log N + M log M) | Space: O(1) extra
# ============================================================
class Solution1:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()

        result = []
        i = j = 0

        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                result.append(nums1[i])
                i += 1; j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1

        return result

# ============================================================
# Solution 2: Hash Map Frequency (Optimal)
# Time: O(N + M) | Space: O(min(N,M))
# ============================================================
class Solution2:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # Pythonic: Counter intersection
        return list((Counter(nums1) & Counter(nums2)).elements())
