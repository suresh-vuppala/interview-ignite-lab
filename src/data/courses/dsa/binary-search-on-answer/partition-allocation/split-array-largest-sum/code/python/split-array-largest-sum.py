# Time: O(N * log(sum - max))
# Space: O(1)

def splitArray(nums, k):
    left, right = max(nums), sum(nums)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canSplit(nums, k, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canSplit(nums, k, maxSum):
    subarrays, currentSum = 1, 0
    
    for num in nums:
        if currentSum + num > maxSum:
            subarrays += 1
            currentSum = num
        else:
            currentSum += num
    
    return subarrays <= k
