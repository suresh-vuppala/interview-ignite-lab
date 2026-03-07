# Time: O(n log(m * k)), Space: O(1)

def minimumTime(time, totalTrips):
    left, right = 1, min(time) * totalTrips
    
    while left <= right:
        mid = (left + right) // 2
        trips = sum(mid // t for t in time)
        
        if trips >= totalTrips:
            right = mid - 1
        else:
            left = mid + 1
    
    return left
