class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n²) | Space: O(1)
    def longestOnesBruteForce(self, nums, k):
        n = len(nums)
        max_len = 0
        
        # Check all subarrays
        for i in range(n):
            zeros = 0
            for j in range(i, n):
                # Count zeros
                if nums[j] == 0:
                    zeros += 1
                
                # Check if valid
                if zeros <= k:
                    max_len = max(max_len, j - i + 1)
                else:
                    break  # No point continuing, more zeros ahead
        
        return max_len
    
    # ==================== SOLUTION 2: SLIDING WINDOW ====================
    # Time: O(n) | Space: O(1)
    def longestOnesSlidingWindow(self, nums, k):
        n = len(nums)
        left = 0
        zeros = 0
        max_len = 0
        
        for right in range(n):
            # Add element to window
            if nums[right] == 0:
                zeros += 1
            
            # Shrink window while invalid
            while zeros > k:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
            
            # Update max length
            max_len = max(max_len, right - left + 1)
        
        return max_len
    
    # ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    # Time: O(n) | Space: O(1)
    def longestOnesOptimized(self, nums, k):
        left = 0
        zeros = 0
        
        for right in range(len(nums)):
            # Add element to window
            if nums[right] == 0:
                zeros += 1
            
            # If invalid, slide window (maintain size)
            if zeros > k:
                if nums[left] == 0:
                    zeros -= 1
                left += 1
        
        # Window size is the answer
        return len(nums) - left
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def longestOnes(self, nums, k):
        return self.longestOnesSlidingWindow(nums, k)
