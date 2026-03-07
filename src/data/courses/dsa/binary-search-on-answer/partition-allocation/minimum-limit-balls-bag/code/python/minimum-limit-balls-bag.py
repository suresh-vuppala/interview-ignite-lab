# Time: O(N * log(max(nums)))
# Space: O(1)

def minimumSize(nums, maxOperations):
    left, right = 1, max(nums)
    result = right
    
    while left <= right:
        mid = (left + right) // 2
        if canAchieve(nums, maxOperations, mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return result

def canAchieve(nums, maxOps, maxBalls):
    operations = 0
    for num in nums:
        if num > maxBalls:
            operations += (num - 1) // maxBalls
    return operations <= maxOps
