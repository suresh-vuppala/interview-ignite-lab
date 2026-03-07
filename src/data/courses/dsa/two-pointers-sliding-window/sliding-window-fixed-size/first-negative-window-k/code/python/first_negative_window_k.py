from collections import deque

class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n×k) | Space: O(1)
    def firstNegativeBruteForce(self, arr, k):
        n = len(arr)
        result = []
        
        # For each window
        for i in range(n - k + 1):
            # Find first negative in window
            first_neg = 0
            for j in range(i, i + k):
                if arr[j] < 0:
                    first_neg = arr[j]
                    break
            result.append(first_neg)
        
        return result
    
    # ==================== SOLUTION 2: SLIDING WINDOW WITH DEQUE - OPTIMAL ====================
    # Time: O(n) | Space: O(k)
    def firstNegativeDeque(self, arr, k):
        n = len(arr)
        result = []
        dq = deque()  # Store indices of negative numbers
        
        # Process first window
        for i in range(k):
            if arr[i] < 0:
                dq.append(i)
        
        # First window result
        result.append(arr[dq[0]] if dq else 0)
        
        # Process remaining windows
        for i in range(k, n):
            # Remove indices outside current window
            while dq and dq[0] <= i - k:
                dq.popleft()
            
            # Add current element if negative
            if arr[i] < 0:
                dq.append(i)
            
            # First negative in current window
            result.append(arr[dq[0]] if dq else 0)
        
        return result
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def firstNegative(self, arr, k):
        return self.firstNegativeDeque(arr, k)
