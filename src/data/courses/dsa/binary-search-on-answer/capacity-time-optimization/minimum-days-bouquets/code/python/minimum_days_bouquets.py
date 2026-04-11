class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay): return -1
        lo, hi = 1, max(bloomDay)
        while lo < hi:
            mid = (lo + hi) // 2
            bouquets = flowers = 0
            for d in bloomDay:
                if d <= mid: flowers += 1
                else: flowers = 0
                if flowers == k: bouquets += 1; flowers = 0
            if bouquets >= m: hi = mid
            else: lo = mid + 1
        return lo