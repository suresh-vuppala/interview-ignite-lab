# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N³) | Space: O(1)

def count_odd_even_brute(nums):
    n = len(nums)
    count = 0
    
    for i in range(n):
        for j in range(i, n):
            odd_count = 0
            even_count = 0
            for idx in range(i, j + 1):
                if nums[idx] % 2 == 1:
                    odd_count += 1
                else:
                    even_count += 1
            
            if odd_count == even_count:
                count += 1
    
    return count


# ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
# Time: O(N²) | Space: O(1)

def count_odd_even_optimized(nums):
    n = len(nums)
    count = 0
    
    for i in range(n):
        odd_count = 0
        even_count = 0
        
        for j in range(i, n):
            if nums[j] % 2 == 1:
                odd_count += 1
            else:
                even_count += 1
            
            if odd_count == even_count:
                count += 1
    
    return count


# ==================== SOLUTION 3: TRANSFORM + PREFIX SUM ====================
# Time: O(N) | Space: O(N)

def count_odd_even_prefix_sum(nums):
    """
    Transform: odd → +1, even → -1
    Problem becomes: count subarrays with sum = 0
    """
    prefix_sum_map = {0: 1}  # Empty prefix
    prefix_sum = 0
    count = 0
    
    for num in nums:
        # Transform: odd → +1, even → -1
        if num % 2 == 1:
            prefix_sum += 1
        else:
            prefix_sum -= 1
        
        # If this prefix sum seen before, all previous occurrences
        # form valid subarrays (sum = 0) with current position
        if prefix_sum in prefix_sum_map:
            count += prefix_sum_map[prefix_sum]
            prefix_sum_map[prefix_sum] += 1
        else:
            prefix_sum_map[prefix_sum] = 1
    
    return count


# ==================== MAIN SOLUTION (RECOMMENDED) ====================

def countOddEvenSubarrays(nums):
    """
    Count subarrays with equal odd and even counts.
    
    Time: O(N) - single pass
    Space: O(N) - HashMap
    
    Example:
        >>> countOddEvenSubarrays([2, 5, 4, 6, 3, 1])
        6
    """
    return count_odd_even_prefix_sum(nums)
