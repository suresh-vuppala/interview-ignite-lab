class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        lo, hi = 1, position[-1] - position[0]
        while lo < hi:
            mid = lo + (hi - lo + 1) // 2
            count, last = 1, position[0]
            for p in position[1:]:
                if p - last >= mid: count += 1; last = p
            if count >= m: lo = mid
            else: hi = mid - 1
        return lo