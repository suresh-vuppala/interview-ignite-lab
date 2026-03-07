class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n²) | Space: O(1)
    public int longestOnesBruteForce(int[] nums, int k) {
        int n = nums.length;
        int maxLen = 0;
        
        // Check all subarrays
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                // Count zeros
                if (nums[j] == 0) {
                    zeros++;
                }
                
                // Check if valid
                if (zeros <= k) {
                    maxLen = Math.max(maxLen, j - i + 1);
                } else {
                    break;  // No point continuing
                }
            }
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW ====================
    // Time: O(n) | Space: O(1)
    public int longestOnesSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int left = 0;
        int zeros = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            // Add element to window
            if (nums[right] == 0) {
                zeros++;
            }
            
            // Shrink window while invalid
            while (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            
            // Update max length
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    // Time: O(n) | Space: O(1)
    public int longestOnesOptimized(int[] nums, int k) {
        int left = 0;
        int zeros = 0;
        
        for (int right = 0; right < nums.length; right++) {
            // Add element to window
            if (nums[right] == 0) {
                zeros++;
            }
            
            // If invalid, slide window (maintain size)
            if (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
        }
        
        // Window size is the answer
        return nums.length - left;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public int longestOnes(int[] nums, int k) {
        return longestOnesSlidingWindow(nums, k);
    }
}
