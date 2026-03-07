# Time: O(N log N + N * log(max - min))
# Space: O(1)

def maxDistance(position, m):
    position.sort()
    left, right = 1, position[-1] - position[0]
    result = 0
    
    while left <= right:
        mid = (left + right) // 2
        if canPlaceBalls(position, m, mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    
    return result

def canPlaceBalls(position, m, minForce):
    balls, lastPos = 1, position[0]
    
    for i in range(1, len(position)):
        if position[i] - lastPos >= minForce:
            balls += 1
            lastPos = position[i]
            if balls == m:
                return True
    
    return False
