# ==================== SOLUTION 1: BRUTE FORCE ====================
# Time: O(N×K) | Space: O(N)
def distinct_elements_brute(arr, k):
    n = len(arr)
    result = []
    
    # For each window
    for i in range(n - k + 1):
        distinct = set()
        # Add all elements in window to set
        for j in range(i, i + k):
            distinct.add(arr[j])
        result.append(len(distinct))
    
    return result


# ==================== SOLUTION 2: SLIDING WINDOW WITH HASHMAP ====================
# Time: O(N) | Space: O(N)
def distinct_elements_sliding(arr, k):
    n = len(arr)
    if n < k:
        return []
    
    freq = {}
    result = []
    
    # Build first window
    for i in range(k):
        freq[arr[i]] = freq.get(arr[i], 0) + 1
    result.append(len(freq))
    
    # Slide the window
    for i in range(k, n):
        # Remove leftmost element of previous window
        left_elem = arr[i - k]
        freq[left_elem] -= 1
        if freq[left_elem] == 0:
            del freq[left_elem]
        
        # Add new element to window
        freq[arr[i]] = freq.get(arr[i], 0) + 1
        
        # Count distinct elements
        result.append(len(freq))
    
    return result


# ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
# Time: O(N) | Space: O(N)
def distinct_elements_optimized(arr, k):
    n = len(arr)
    
    # Edge cases
    if k <= 0 or k > n:
        return []
    
    freq = {}
    result = []
    
    # Process first window
    for i in range(k):
        freq[arr[i]] = freq.get(arr[i], 0) + 1
    result.append(len(freq))
    
    # Slide window from k to n-1
    for i in range(k, n):
        # Remove element going out of window
        out_elem = arr[i - k]
        freq[out_elem] -= 1
        if freq[out_elem] == 0:
            del freq[out_elem]
        
        # Add element coming into window
        in_elem = arr[i]
        freq[in_elem] = freq.get(in_elem, 0) + 1
        
        # Record distinct count
        result.append(len(freq))
    
    return result


# Main solution - recommended approach
def distinct_elements_window(arr, k):
    """Count distinct elements in every window of size k."""
    return distinct_elements_sliding(arr, k)
