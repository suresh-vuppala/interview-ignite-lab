class Solution:
    def minSpeedOnTime(self, dist, hour):
        import math
        if len(dist) - 1 >= hour: return -1
        lo, hi = 1, 10**7
        while lo < hi:
            mid = (lo + hi) // 2
            t = sum(math.ceil(d / mid) for d in dist[:-1]) + dist[-1] / mid
            if t <= hour: hi = mid
            else: lo = mid + 1
        return lo