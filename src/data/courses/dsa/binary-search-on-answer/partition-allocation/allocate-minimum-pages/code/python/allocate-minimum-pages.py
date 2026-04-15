# Time: O(N * log(sum - max))
# Space: O(1)

def allocateBooks(books, m):
    n = len(books)
    
    # Edge case: More students than books
    if m > n:
        return -1
    
    # Binary search range
    low = max(books)   # Minimum possible answer
    high = sum(books)  # Maximum possible answer
    result = high
    
    while low <= high:
        mid = (low + high) // 2
        
        # Check if we can allocate with max pages = mid
        if canAllocate(books, n, m, mid):
            result = mid      # This works, try smaller
            high = mid - 1
        else:
            low = mid + 1     # Too small, need larger limit
    
    return result

def canAllocate(books, n, m, maxPages):
    studentCount = 1      # Start with first student
    currentPages = 0      # Pages assigned to current student
    
    for i in range(n):
        # If a single book has more pages than our limit, impossible
        if books[i] > maxPages:
            return False
        
        # Try to assign current book to current student
        if currentPages + books[i] <= maxPages:
            currentPages += books[i]  # Assign to current student
        else:
            # Current student's limit reached, assign to next student
            studentCount += 1
            currentPages = books[i]   # Start new student with current book
            
            # If we need more students than available, this limit is too small
            if studentCount > m:
                return False
    
    # Successfully allocated all books within the limit
    return True
