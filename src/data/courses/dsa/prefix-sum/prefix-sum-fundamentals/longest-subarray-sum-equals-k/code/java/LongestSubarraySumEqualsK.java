import java.util.*;

public class LongestSubarraySumEqualsK {
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N³) | Space: O(1)
    
    public static int longestSubarrayBrute(int[] nums, int k) {
        int n = nums.length;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int subarraySum = 0;
                for (int idx = i; idx <= j; idx++) {
                    subarraySum += nums[idx];
                }
                if (subarraySum == k) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    // Time: O(N²) | Space: O(1)
    
    public static int longestSubarrayOptimized(int[] nums, int k) {
        int n = nums.length;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                currentSum += nums[j];
                if (currentSum == k) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== SOLUTION 3: PREFIX SUM WITH HASHMAP ====================
    // Time: O(N) | Space: O(N)
    
    public static int longestSubarrayPrefixSum(int[] nums, int k) {
        Map<Integer, Integer> prefixSumMap = new HashMap<>();
        prefixSumMap.put(0, -1);  // Empty prefix before index 0
        
        int prefixSum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            
            // Check if (prefixSum - k) exists
            if (prefixSumMap.containsKey(prefixSum - k)) {
                int length = i - prefixSumMap.get(prefixSum - k);
                maxLen = Math.max(maxLen, length);
            }
            
            // Store first occurrence only (to maximize length)
            if (!prefixSumMap.containsKey(prefixSum)) {
                prefixSumMap.put(prefixSum, i);
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== SOLUTION 4: SLIDING WINDOW (POSITIVE ONLY) ====================
    // Time: O(N) | Space: O(1)
    
    public static int longestSubarraySlidingWindow(int[] nums, int k) {
        int left = 0;
        int currentSum = 0;
        int maxLen = 0;
        
        for (int right = 0; right < nums.length; right++) {
            currentSum += nums[right];
            
            while (currentSum > k && left <= right) {
                currentSum -= nums[left];
                left++;
            }
            
            if (currentSum == k) {
                maxLen = Math.max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
    
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    
    public static int longestSubarraySumK(int[] nums, int k) {
        /*
         * Find length of longest subarray with sum equal to k.
         * 
         * Time: O(N) - single pass
         * Space: O(N) - HashMap
         * 
         * Works with negative numbers and zeros.
         */
        return longestSubarrayPrefixSum(nums, k);
    }
}
