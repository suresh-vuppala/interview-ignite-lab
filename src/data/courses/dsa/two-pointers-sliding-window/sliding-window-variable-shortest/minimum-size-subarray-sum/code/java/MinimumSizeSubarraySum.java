class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n²) | Space: O(1)
    public int minSubArrayLenBruteForce(int target, int[] nums) {
        int n = nums.length;
        int minLen = Integer.MAX_VALUE;
        
        // Check all subarrays
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                
                // Check if sum >= target
                if (currentSum >= target) {
                    minLen = Math.min(minLen, j - i + 1);
                    break;  // No need to extend further
                }
            }
        }
        
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW - OPTIMAL ====================
    // Time: O(n) | Space: O(1)
    public int minSubArrayLenSlidingWindow(int target, int[] nums) {
        int n = nums.length;
        int left = 0;
        int currentSum = 0;
        int minLen = Integer.MAX_VALUE;
        
        for (int right = 0; right < n; right++) {
            // Add element to window
            currentSum += nums[right];
            
            // Shrink window while sum >= target
            while (currentSum >= target) {
                minLen = Math.min(minLen, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
    
    // ==================== SOLUTION 3: BINARY SEARCH + PREFIX SUM ====================
    // Time: O(n log n) | Space: O(n)
    public int minSubArrayLenBinarySearch(int target, int[] nums) {
        int n = nums.length;
        
        // Build prefix sum
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        int minLen = Integer.MAX_VALUE;
        
        // For each starting position
        for (int i = 0; i < n; i++) {
            // Binary search for smallest j where sum[i:j] >= target
            int toFind = target + prefix[i];
            int left = i + 1, right = n;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (prefix[mid] >= toFind) {
                    minLen = Math.min(minLen, mid - i);
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public int minSubArrayLen(int target, int[] nums) {
        return minSubArrayLenSlidingWindow(target, nums);
    }
}
