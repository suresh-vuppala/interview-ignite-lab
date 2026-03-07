# Time: O(N * log(max - min))
# Space: O(1)

def minDays(bloomDay, m, k):
    if m * k > len(bloomDay):
        return -1
    
    left, right = min(bloomDay), max(bloomDay)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canMakeBouquets(bloomDay, m, k, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canMakeBouquets(bloomDay, m, k, day):
    bouquets, flowers = 0, 0
    
    for bloom in bloomDay:
        if bloom <= day:
            flowers += 1
            if flowers == k:
                bouquets += 1
                flowers = 0
        else:
            flowers = 0
    
    return bouquets >= m
