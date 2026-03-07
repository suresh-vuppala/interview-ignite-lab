# Time: O(N log N + N * log(max - min))
# Space: O(1)

def aggressiveCows(stalls, c):
    stalls.sort()
    left, right = 1, stalls[-1] - stalls[0]
    result = 0
    
    while left <= right:
        mid = (left + right) // 2
        if canPlaceCows(stalls, c, mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    
    return result

def canPlaceCows(stalls, c, minDist):
    cows, lastPos = 1, stalls[0]
    
    for i in range(1, len(stalls)):
        if stalls[i] - lastPos >= minDist:
            cows += 1
            lastPos = stalls[i]
            if cows == c:
                return True
    
    return False
