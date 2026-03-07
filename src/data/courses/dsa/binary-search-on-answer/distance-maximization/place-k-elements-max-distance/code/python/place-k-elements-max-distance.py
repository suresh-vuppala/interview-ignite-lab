# Time: O(N log N + N * log(max - min))
# Space: O(1)

def placeKElements(arr, k):
    arr.sort()
    left, right = 1, arr[-1] - arr[0]
    result = 0
    
    while left <= right:
        mid = (left + right) // 2
        if canSelect(arr, k, mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    
    return result

def canSelect(arr, k, minDist):
    count, lastPos = 1, arr[0]
    
    for i in range(1, len(arr)):
        if arr[i] - lastPos >= minDist:
            count += 1
            lastPos = arr[i]
            if count == k:
                return True
    
    return False
