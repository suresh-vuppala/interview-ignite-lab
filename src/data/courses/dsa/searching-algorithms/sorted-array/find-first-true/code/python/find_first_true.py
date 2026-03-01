def find_first_true(arr):
    """
    Find first true in sorted boolean array
    Time: O(log n), Space: O(1)
    """
    left, right = 0, len(arr) - 1
    result = -1
    
    while left <= right:
        mid = left + (right - left) // 2
        
        if arr[mid]:
            result = mid  # Record this as potential answer
            right = mid - 1  # Continue searching left
        else:
            left = mid + 1  # Search right
    
    return result

if __name__ == "__main__":
    arr = [False, False, False, True, True, True]
    
    result = find_first_true(arr)
    print(f"Index: {result}")  # Output: 3
