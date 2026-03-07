# Time: O(N * log(max(piles)))
# Space: O(1)

def minEatingSpeed(piles, h):
    left, right = 1, max(piles)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canEatAll(piles, h, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canEatAll(piles, h, speed):
    hours = 0
    for pile in piles:
        hours += (pile + speed - 1) // speed
    return hours <= h
