class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        lo, hi = max(weights), sum(weights)
        while lo < hi:
            mid = (lo + hi) // 2
            d, load = 1, 0
            for w in weights:
                if load + w > mid: d += 1; load = 0
                load += w
            if d <= days: hi = mid
            else: lo = mid + 1
        return lo