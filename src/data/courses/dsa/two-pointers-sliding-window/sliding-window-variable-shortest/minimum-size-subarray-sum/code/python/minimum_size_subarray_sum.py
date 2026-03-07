class Solution:
    # ==================== SOLUTION 1: BRUTE FORCE ====================
    # Time: O(n²) | Space: O(1)
    def minSubArrayLenBruteForce(self, target, nums):
        n = len(nums)
        min_len = float('inf')
        
        # Check all subarrays
        for i in range(n):
            current_sum = 0
            for j in range(i, n):
                current_sum += nums[j]
                
                # Check if sum >= target
                if current_sum >= target:
                    min_len = min(min_len, j - i + 1)
                    break  # No need to extend further
        
        return min_len if min_len != float('inf') else 0
    
    # ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    # Time: O(n) | Space: O(1)
    def minSubArrayLenSlidingWindow(self, target, nums):
        n = len(nums)
        left = 0
        current_sum = 0
        min_len = float('inf')
        
        for right in range(n):
            # Add element to window
            current_sum += nums[right]
            
            # Shrink window while sum >= target
            while current_sum >= target:
                min_len = min(min_len, right - left + 1)
                current_sum -= nums[left]
                left += 1
        
        return min_len if min_len != float('inf') else 0
    
    # ==================== SOLUTION 3: BINARY SEARCH + PREFIX SUM ====================
    # Time: O(n log n) | Space: O(n)
    def minSubArrayLenBinarySearch(self, target, nums):
        n = len(nums)
        
        # Build prefix sum
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        
        min_len = float('inf')
        
        # For each starting position
        for i in range(n):
            # Binary search for smallest j where sum[i:j] >= target
            to_find = target + prefix[i]
            left, right = i + 1, n
            
            while left <= right:
                mid = (left + right) // 2
                if prefix[mid] >= to_find:
                    min_len = min(min_len, mid - i)
                    right = mid - 1
                else:
                    left = mid + 1
        
        return min_len if min_len != float('inf') else 0
    
    # ==================== MAIN SOLUTION (RECOMMENDED) ====================
    def minSubArrayLen(self, target, nums):
        return self.minSubArrayLenSlidingWindow(target, nums)
