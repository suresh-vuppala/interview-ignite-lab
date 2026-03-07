# Time: O(k^N * log(sum - max))
# Space: O(N + k)

def minimumTimeRequired(jobs, k):
    jobs.sort(reverse=True)
    left, right = max(jobs), sum(jobs)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canAssign(jobs, k, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canAssign(jobs, k, maxTime):
    workers = [0] * k
    return backtrack(jobs, 0, workers, maxTime)

def backtrack(jobs, index, workers, maxTime):
    if index == len(jobs):
        return True
    
    for i in range(len(workers)):
        if workers[i] + jobs[index] <= maxTime:
            workers[i] += jobs[index]
            if backtrack(jobs, index + 1, workers, maxTime):
                return True
            workers[i] -= jobs[index]
        if workers[i] == 0:
            break
    
    return False
