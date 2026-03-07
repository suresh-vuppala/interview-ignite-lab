class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n×k) | Space: O(1)
    def maxSumBruteForce(self, arr, k):
        n = len(arr)
        max_sum = float('-inf')
        
        # Check each window of size k
        for i in range(n - k + 1):
            # Calculate sum of current window
            window_sum = 0
            for j in range(i, i + k):
                window_sum += arr[j]
            # Update maximum
            max_sum = max(max_sum, window_sum)
        
        return max_sum
    
    # ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    # Time: O(n) | Space: O(1)
    def maxSumSlidingWindow(self, arr, k):
        n = len(arr)
        
        # Calculate sum of first window
        window_sum = sum(arr[:k])
        max_sum = window_sum
        
        # Slide window and update max
        for i in range(k, n):
            # Remove leftmost, add rightmost
            window_sum = window_sum - arr[i - k] + arr[i]
            max_sum = max(max_sum, window_sum)
        
        return max_sum
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def maxSum(self, arr, k):
        return self.maxSumSlidingWindow(arr, k)
