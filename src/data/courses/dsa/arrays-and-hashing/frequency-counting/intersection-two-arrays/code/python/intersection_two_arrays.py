class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # O(n + m) time — Counter intersection
        from collections import Counter
        c1, c2 = Counter(nums1), Counter(nums2)
        return list((c1 & c2).elements())  # & takes min frequency