# Time: O(n log m), Space: O(1)

def minSpeedOnTime(dist, hour):
    n = len(dist)
    if hour <= n - 1:
        return -1
    
    left, right = 1, 10**7
    
    while left <= right:
        mid = (left + right) // 2
        time = sum((d + mid - 1) // mid for d in dist[:-1])
        time += dist[-1] / mid
        
        if time <= hour:
            right = mid - 1
        else:
            left = mid + 1
    
    return left
