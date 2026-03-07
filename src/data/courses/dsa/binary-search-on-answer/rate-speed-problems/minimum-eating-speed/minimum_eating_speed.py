# Time: O(n log m), Space: O(1)

def minEatingSpeed(piles, h):
    left, right = 1, max(piles)
    
    while left <= right:
        mid = (left + right) // 2
        hours = sum((pile + mid - 1) // mid for pile in piles)
        
        if hours <= h:
            right = mid - 1
        else:
            left = mid + 1
    
    return left
