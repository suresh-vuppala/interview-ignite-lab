# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N³) | Space: O(1)

def subarrays_divisible_brute(nums, k):
    """
    Generate all subarrays and check if sum is divisible by k.
    
    For each starting position i:
        For each ending position j:
            Calculate sum of subarray [i...j]
            If sum % k == 0, count it
    """
    n = len(nums)
    count = 0
    
    # Try all starting positions
    for i in range(n):
        # Try all ending positions
        for j in range(i, n):
            # Calculate sum of subarray [i...j]
            subarray_sum = 0
            for idx in range(i, j + 1):
                subarray_sum += nums[idx]
            
            # Check if divisible by k
            if subarray_sum % k == 0:
                count += 1
    
    return count


# ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
# Time: O(N²) | Space: O(1)

def subarrays_divisible_optimized(nums, k):
    """
    Use running sum to avoid recalculating sum for each subarray.
    
    For each starting position i:
        Maintain currentSum as we extend to j
        Just add nums[j] instead of recalculating entire sum
    """
    n = len(nums)
    count = 0
    
    # Try all starting positions
    for i in range(n):
        current_sum = 0
        
        # Extend to all ending positions
        for j in range(i, n):
            current_sum += nums[j]  # Add current element
            
            # Check if divisible by k
            if current_sum % k == 0:
                count += 1
    
    return count


# ==================== SOLUTION 3: PREFIX SUM WITH HASHMAP ====================
# Time: O(N) | Space: O(K)

def subarrays_divisible_prefix_sum(nums, k):
    """
    Use prefix sum modulo k with HashMap.
    
    Key insight: If prefixSum[j] % k == prefixSum[i] % k,
    then subarray [i+1...j] has sum divisible by k.
    
    Store frequency of each remainder in HashMap.
    When we see a remainder again, all previous occurrences
    form valid subarrays with current position.
    """
    # HashMap to store remainder -> frequency
    remainder_count = {0: 1}  # Empty prefix has remainder 0
    
    prefix_sum = 0
    count = 0
    
    for num in nums:
        # Update prefix sum
        prefix_sum += num
        
        # Calculate remainder (handle negative remainders)
        remainder = prefix_sum % k
        if remainder < 0:
            remainder += k  # Ensure remainder is in [0, k-1]
        
        # If this remainder seen before, all previous occurrences
        # form valid subarrays with current position
        if remainder in remainder_count:
            count += remainder_count[remainder]
            remainder_count[remainder] += 1
        else:
            remainder_count[remainder] = 1
    
    return count


# ==================== MAIN SOLUTION (RECOMMENDED) ====================

def subarraysDivByK(nums, k):
    """
    Count subarrays with sum divisible by k.
    
    Time: O(N) - single pass through array
    Space: O(K) - HashMap stores at most K remainders
    
    Args:
        nums: List of integers
        k: Divisor
    
    Returns:
        Number of subarrays with sum divisible by k
    
    Example:
        >>> subarraysDivByK([4, 5, 0, -2, -3, 1], 5)
        7
    """
    return subarrays_divisible_prefix_sum(nums, k)
