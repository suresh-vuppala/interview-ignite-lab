def square_root(n):
    """
    Find integer square root (floor of sqrt)
    Time: O(log n), Space: O(1)
    """
    if n < 2:
        return n
    
    left, right = 0, n
    
    while left <= right:
        mid = left + (right - left) // 2
        square = mid * mid
        
        if square == n:
            return mid
        elif square < n:
            left = mid + 1  # Answer is larger
        else:
            right = mid - 1  # Answer is smaller
    
    return right  # Largest integer whose square <= n

if __name__ == "__main__":
    print(square_root(16))   # Output: 4
    print(square_root(17))   # Output: 4
    print(square_root(25))   # Output: 5
