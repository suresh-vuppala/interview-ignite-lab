class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        lo, hi = 1, max(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            ops = sum((n - 1) // mid for n in nums)
            if ops <= maxOperations: hi = mid
            else: lo = mid + 1
        return lo