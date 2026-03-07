class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n×k) | Space: O(1)
    def subarraySumBruteForce(self, arr, k):
        n = len(arr)
        result = []
        
        # For each starting position
        for i in range(n - k + 1):
            # Calculate sum of k elements
            window_sum = 0
            window = []
            for j in range(i, i + k):
                window_sum += arr[j]
                window.append(arr[j])
            result.append([window, window_sum])
        
        return result
    
    # ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    # Time: O(n) | Space: O(1)
    def subarraySumSlidingWindow(self, arr, k):
        n = len(arr)
        result = []
        
        # Calculate sum of first window
        window_sum = sum(arr[:k])
        result.append([arr[:k], window_sum])
        
        # Slide window
        for i in range(k, n):
            # Remove leftmost element, add rightmost element
            window_sum = window_sum - arr[i - k] + arr[i]
            result.append([arr[i - k + 1:i + 1], window_sum])
        
        return result
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def subarraySum(self, arr, k):
        return self.subarraySumSlidingWindow(arr, k)
