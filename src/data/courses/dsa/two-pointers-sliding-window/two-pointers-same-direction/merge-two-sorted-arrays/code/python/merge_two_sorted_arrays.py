# ============================================================
# Merge Sorted Array
# ============================================================

from typing import List

# ============================================================
# Solution 1: Copy + Sort
# Time: O((M+N) log(M+N)) | Space: O(1)
# ============================================================
class Solution1:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        nums1[m:] = nums2
        nums1.sort()

# ============================================================
# Solution 2: Three Pointers from End (Optimal)
# Time: O(M+N) | Space: O(1)
# ============================================================
class Solution2:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i, j, k = m - 1, n - 1, m + n - 1

        # Fill from back: place larger element at position k
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
