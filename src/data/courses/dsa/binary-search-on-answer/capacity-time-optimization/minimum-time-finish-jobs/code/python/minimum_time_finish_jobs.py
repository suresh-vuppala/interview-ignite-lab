class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        jobs.sort(reverse=True)
        lo, hi = max(jobs), sum(jobs)
        def can_finish(idx, workers, limit):
            if idx == len(jobs): return True
            for i in range(len(workers)):
                if workers[i] + jobs[idx] <= limit:
                    workers[i] += jobs[idx]
                    if can_finish(idx+1, workers, limit): return True
                    workers[i] -= jobs[idx]
                if workers[i] == 0: break
            return False
        while lo < hi:
            mid = (lo + hi) // 2
            if can_finish(0, [0]*k, mid): hi = mid
            else: lo = mid + 1
        return lo