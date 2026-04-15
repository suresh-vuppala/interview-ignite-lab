# Time: O(N * log(sum - max))
# Space: O(1)

def splitArray(nums, k):
    n = len(nums)
    
    # Binary search range
    low = max(nums)   # Minimum possible answer
    high = sum(nums)  # Maximum possible answer
    result = high
    
    while low <= high:
        mid = (low + high) // 2
        
        # Check if we can split with max sum = mid
        if canSplit(nums, n, k, mid):
            result = mid      # This works, try smaller
            high = mid - 1
        else:
            low = mid + 1     # Too small, need larger limit
    
    return result

def canSplit(nums, n, k, maxSum):
    subarrayCount = 1     # Start with first subarray
    currentSum = 0        # Sum of current subarray
    
    for i in range(n):
        # If a single element is larger than our limit, impossible
        if nums[i] > maxSum:
            return False
        
        # Try to add current element to current subarray
        if currentSum + nums[i] <= maxSum:
            currentSum += nums[i]  # Add to current subarray
        else:
            # Current subarray's limit reached, start new subarray
            subarrayCount += 1
            currentSum = nums[i]   # Start new subarray with current element
            
            # If we need more subarrays than allowed, this limit is too small
            if subarrayCount > k:
                return False
    
    # Successfully split into k or fewer subarrays within the limit
    return True
