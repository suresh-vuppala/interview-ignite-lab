from collections import deque
import heapq

class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n×k) | Space: O(1)
    def maxSlidingWindowBruteForce(self, arr, k):
        n = len(arr)
        result = []
        
        # For each window
        for i in range(n - k + 1):
            # Find max in window
            window_max = max(arr[i:i + k])
            result.append(window_max)
        
        return result
    
    # ==================== SOLUTION 2: MONOTONIC DEQUE - OPTIMAL ====================
    # Time: O(n) | Space: O(k)
    def maxSlidingWindowDeque(self, arr, k):
        n = len(arr)
        result = []
        dq = deque()  # Store indices in decreasing order of values
        
        for i in range(n):
            # Remove indices outside current window
            while dq and dq[0] <= i - k:
                dq.popleft()
            
            # Remove indices with smaller values (can't be max)
            while dq and arr[dq[-1]] < arr[i]:
                dq.pop()
            
            # Add current index
            dq.append(i)
            
            # Add max to result (after first window is complete)
            if i >= k - 1:
                result.append(arr[dq[0]])
        
        return result
    
    # ==================== SOLUTION 3: USING MAX HEAP ====================
    # Time: O(n log k) | Space: O(k)
    def maxSlidingWindowHeap(self, arr, k):
        n = len(arr)
        result = []
        heap = []  # Max heap: store (-value, index)
        
        # Add first k elements
        for i in range(k):
            heapq.heappush(heap, (-arr[i], i))
        
        result.append(-heap[0][0])
        
        # Process remaining elements
        for i in range(k, n):
            # Add new element
            heapq.heappush(heap, (-arr[i], i))
            
            # Remove elements outside window
            while heap and heap[0][1] <= i - k:
                heapq.heappop(heap)
            
            # Top is maximum
            result.append(-heap[0][0])
        
        return result
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def maxSlidingWindow(self, arr, k):
        return self.maxSlidingWindowDeque(arr, k)
