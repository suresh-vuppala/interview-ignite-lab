# Time: O(N * log(sum - max))
# Space: O(1)

def allocateBooks(arr, m):
    if m > len(arr):
        return -1
    
    left, right = max(arr), sum(arr)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canAllocate(arr, m, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canAllocate(arr, m, maxPages):
    students, currentPages = 1, 0
    
    for pages in arr:
        if currentPages + pages > maxPages:
            students += 1
            currentPages = pages
        else:
            currentPages += pages
    
    return students <= m
