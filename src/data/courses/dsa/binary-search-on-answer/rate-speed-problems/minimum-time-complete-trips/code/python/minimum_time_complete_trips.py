class Solution:
    def minimumTime(self, time, totalTrips):
        lo, hi = 1, max(time) * totalTrips
        while lo < hi:
            mid = (lo + hi) // 2
            trips = sum(mid // t for t in time)
            if trips >= totalTrips: hi = mid
            else: lo = mid + 1
        return lo