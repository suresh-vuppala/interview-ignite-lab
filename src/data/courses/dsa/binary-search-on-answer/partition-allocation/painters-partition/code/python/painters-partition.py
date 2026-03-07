# Time: O(N * log(sum - max))
# Space: O(1)

def paintersPartition(arr, m):
    if m > len(arr):
        return -1
    
    left, right = max(arr), sum(arr)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canPaint(arr, m, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canPaint(arr, m, maxTime):
    painters, currentTime = 1, 0
    
    for time in arr:
        if currentTime + time > maxTime:
            painters += 1
            currentTime = time
        else:
            currentTime += time
    
    return painters <= m
