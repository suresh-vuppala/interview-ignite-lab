# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N³) | Space: O(1)

def longest_subarray_brute(nums, k):
    n = len(nums)
    max_len = 0
    
    for i in range(n):
        for j in range(i, n):
            subarray_sum = sum(nums[i:j+1])
            if subarray_sum == k:
                max_len = max(max_len, j - i + 1)
    
    return max_len


# ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
# Time: O(N²) | Space: O(1)

def longest_subarray_optimized(nums, k):
    n = len(nums)
    max_len = 0
    
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += nums[j]
            if current_sum == k:
                max_len = max(max_len, j - i + 1)
    
    return max_len


# ==================== SOLUTION 3: PREFIX SUM WITH HASHMAP ====================
# Time: O(N) | Space: O(N)

def longest_subarray_prefix_sum(nums, k):
    prefix_sum_map = {0: -1}  # Empty prefix before index 0
    prefix_sum = 0
    max_len = 0
    
    for i in range(len(nums)):
        prefix_sum += nums[i]
        
        # Check if (prefixSum - k) exists
        if (prefix_sum - k) in prefix_sum_map:
            length = i - prefix_sum_map[prefix_sum - k]
            max_len = max(max_len, length)
        
        # Store first occurrence only (to maximize length)
        if prefix_sum not in prefix_sum_map:
            prefix_sum_map[prefix_sum] = i
    
    return max_len


# ==================== SOLUTION 4: SLIDING WINDOW (POSITIVE ONLY) ====================
# Time: O(N) | Space: O(1)

def longest_subarray_sliding_window(nums, k):
    left = 0
    current_sum = 0
    max_len = 0
    
    for right in range(len(nums)):
        current_sum += nums[right]
        
        while current_sum > k and left <= right:
            current_sum -= nums[left]
            left += 1
        
        if current_sum == k:
            max_len = max(max_len, right - left + 1)
    
    return max_len


# ==================== MAIN SOLUTION (RECOMMENDED) ====================

def longestSubarraySumK(nums, k):
    """
    Find length of longest subarray with sum equal to k.
    
    Time: O(N) - single pass
    Space: O(N) - HashMap
    
    Works with negative numbers and zeros.
    """
    return longest_subarray_prefix_sum(nums, k)
