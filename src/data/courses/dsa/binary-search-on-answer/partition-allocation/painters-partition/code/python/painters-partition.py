# Time: O(N * log(sum - max))
# Space: O(1)

def paintersPartition(boards, m):
    n = len(boards)
    
    # Edge case: More painters than boards
    if m > n:
        return -1
    
    # Binary search range
    low = max(boards)   # Minimum possible answer
    high = sum(boards)  # Maximum possible answer
    result = high
    
    while low <= high:
        mid = (low + high) // 2
        
        # Check if we can paint with max time = mid
        if canPaint(boards, n, m, mid):
            result = mid      # This works, try smaller
            high = mid - 1
        else:
            low = mid + 1     # Too small, need larger limit
    
    return result

def canPaint(boards, n, m, maxTime):
    painterCount = 1      # Start with first painter
    currentTime = 0       # Time assigned to current painter
    
    for i in range(n):
        # If a single board takes more time than our limit, impossible
        if boards[i] > maxTime:
            return False
        
        # Try to assign current board to current painter
        if currentTime + boards[i] <= maxTime:
            currentTime += boards[i]  # Assign to current painter
        else:
            # Current painter's limit reached, assign to next painter
            painterCount += 1
            currentTime = boards[i]   # Start new painter with current board
            
            # If we need more painters than available, this limit is too small
            if painterCount > m:
                return False
    
    # Successfully painted all boards within the limit
    return True
