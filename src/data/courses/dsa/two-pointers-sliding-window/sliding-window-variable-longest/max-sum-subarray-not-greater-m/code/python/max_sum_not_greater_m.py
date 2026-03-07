from sortedcontainers import SortedList
import bisect

# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N³) | Space: O(1)
def max_sum_brute(arr, M):
    n = len(arr)
    max_sum = 0
    
    # Check all subarrays
    for i in range(n):
        for j in range(i, n):
            # Calculate sum of subarray [i...j]
            current_sum = sum(arr[i:j+1])
            if current_sum <= M:
                max_sum = max(max_sum, current_sum)
    
    return max_sum


# ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
# Time: O(N²) | Space: O(1)
def max_sum_optimized(arr, M):
    n = len(arr)
    max_sum = 0
    
    # For each starting position
    for i in range(n):
        current_sum = 0
        # Extend subarray
        for j in range(i, n):
            current_sum += arr[j]
            if current_sum <= M:
                max_sum = max(max_sum, current_sum)
    
    return max_sum


# ==================== SOLUTION 3: SLIDING WINDOW (POSITIVE INTEGERS) ====================
# Time: O(N) | Space: O(1)
def max_sum_sliding_window(arr, M):
    n = len(arr)
    left = 0
    current_sum = 0
    max_sum = 0
    
    # Expand window with right pointer
    for right in range(n):
        current_sum += arr[right]
        
        # Shrink window if sum exceeds M
        while current_sum > M and left <= right:
            current_sum -= arr[left]
            left += 1
        
        # Update max sum
        max_sum = max(max_sum, current_sum)
    
    return max_sum


# ==================== SOLUTION 4: PREFIX SUM + BINARY SEARCH ====================
# Time: O(N log N) | Space: O(N)
def max_sum_prefix_binary_search(arr, M):
    # Using SortedList for TreeSet-like behavior
    prefix_sums = SortedList([0])
    prefix_sum = 0
    max_sum = 0
    
    for num in arr:
        prefix_sum += num
        
        # Find smallest prefix >= (prefix_sum - M)
        target = prefix_sum - M
        idx = prefix_sums.bisect_left(target)
        
        if idx < len(prefix_sums):
            max_sum = max(max_sum, prefix_sum - prefix_sums[idx])
        
        prefix_sums.add(prefix_sum)
    
    return max_sum


# Alternative implementation without external library
def max_sum_prefix_binary_search_alt(arr, M):
    prefix_sums = [0]
    prefix_sum = 0
    max_sum = 0
    
    for num in arr:
        prefix_sum += num
        
        # Find smallest prefix >= (prefix_sum - M)
        target = prefix_sum - M
        idx = bisect.bisect_left(prefix_sums, target)
        
        if idx < len(prefix_sums):
            max_sum = max(max_sum, prefix_sum - prefix_sums[idx])
        
        # Insert to maintain sorted order
        bisect.insort(prefix_sums, prefix_sum)
    
    return max_sum


# Main solution - recommended approach
def max_sum_not_greater_m(arr, M):
    """Find maximum sum of subarray not greater than M."""
    # Use sliding window for positive integers
    if all(x > 0 for x in arr):
        return max_sum_sliding_window(arr, M)
    # Use prefix sum for arrays with negatives
    return max_sum_prefix_binary_search_alt(arr, M)
