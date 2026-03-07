# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N³) | Space: O(1)
def subarray_product_brute(nums, k):
    n = len(nums)
    count = 0
    
    # Check all subarrays
    for i in range(n):
        for j in range(i, n):
            # Calculate product of subarray [i...j]
            product = 1
            for idx in range(i, j + 1):
                product *= nums[idx]
            
            if product < k:
                count += 1
    
    return count


# ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
# Time: O(N²) | Space: O(1)
def subarray_product_optimized(nums, k):
    n = len(nums)
    count = 0
    
    # For each starting position
    for i in range(n):
        product = 1
        # Extend subarray
        for j in range(i, n):
            product *= nums[j]
            
            if product < k:
                count += 1
            else:
                break  # Product will only increase
    
    return count


# ==================== SOLUTION 3: SLIDING WINDOW ====================
# Time: O(N) | Space: O(1)
def subarray_product_sliding_window(nums, k):
    if k <= 1:
        return 0
    
    left = 0
    product = 1
    count = 0
    
    # Expand window with right pointer
    for right in range(len(nums)):
        product *= nums[right]
        
        # Shrink window if product >= k
        while product >= k and left <= right:
            product //= nums[left]
            left += 1
        
        # Count all subarrays ending at right
        count += (right - left + 1)
    
    return count


# Main solution - recommended approach
def num_subarray_product_less_than_k(nums, k):
    """Count subarrays with product less than k."""
    return subarray_product_sliding_window(nums, k)
