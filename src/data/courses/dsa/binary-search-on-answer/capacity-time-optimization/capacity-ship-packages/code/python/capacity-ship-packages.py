# Time: O(N * log(sum - max))
# Space: O(1)

def shipWithinDays(weights, days):
    left, right = max(weights), sum(weights)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canShip(weights, days, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canShip(weights, days, capacity):
    daysNeeded, currentLoad = 1, 0
    
    for weight in weights:
        if currentLoad + weight > capacity:
            daysNeeded += 1
            currentLoad = weight
        else:
            currentLoad += weight
    
    return daysNeeded <= days
