# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N²) | Space: O(1)
def two_difference_brute(arr, k):
    n = len(arr)
    # Check all pairs
    for i in range(n):
        for j in range(i + 1, n):
            if arr[j] - arr[i] == k:  # Found pair with difference k
                return True
    return False


# ==================== SOLUTION 2: TWO POINTERS ====================
# Time: O(N) | Space: O(1)
def two_difference_two_pointers(arr, k):
    n = len(arr)
    left, right = 0, 1
    
    while right < n:
        diff = arr[right] - arr[left]
        
        # Found the pair
        if diff == k and left != right:
            return True
        
        # Difference too small, move right pointer
        if diff < k:
            right += 1
        # Difference too large, move left pointer
        else:
            left += 1
        
        # Ensure pointers don't overlap
        if left == right:
            right += 1
    
    return False


# ==================== SOLUTION 3: HASHSET ====================
# Time: O(N) | Space: O(N)
def two_difference_hashset(arr, k):
    seen = set()
    
    for num in arr:
        # Check if num + k or num - k exists
        if (num + k) in seen or (num - k) in seen:
            return True
        seen.add(num)
    
    return False


# ==================== SOLUTION 4: BINARY SEARCH ====================
# Time: O(N log N) | Space: O(1)
def two_difference_binary_search(arr, k):
    def binary_search(arr, start, target):
        left, right = start, len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] == target:
                return True
            elif arr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False
    
    # For each element, search for element + k
    for i in range(len(arr)):
        if binary_search(arr, i + 1, arr[i] + k):
            return True
    
    return False


# Main solution - recommended approach
def two_difference(arr, k):
    """Find if pair with difference k exists in sorted array."""
    return two_difference_two_pointers(arr, k)
