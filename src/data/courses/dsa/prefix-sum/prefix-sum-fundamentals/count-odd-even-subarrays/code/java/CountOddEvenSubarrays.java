import java.util.*;

public class CountOddEvenSubarrays {
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N³) | Space: O(1)
    
    public static int countOddEvenBrute(int[] nums) {
        int n = nums.length;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int oddCount = 0;
                int evenCount = 0;
                for (int idx = i; idx <= j; idx++) {
                    if (nums[idx] % 2 == 1) {
                        oddCount++;
                    } else {
                        evenCount++;
                    }
                }
                
                if (oddCount == evenCount) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    // ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    // Time: O(N²) | Space: O(1)
    
    public static int countOddEvenOptimized(int[] nums) {
        int n = nums.length;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int oddCount = 0;
            int evenCount = 0;
            
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 1) {
                    oddCount++;
                } else {
                    evenCount++;
                }
                
                if (oddCount == evenCount) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    
    // ==================== SOLUTION 3: TRANSFORM + PREFIX SUM ====================
    // Time: O(N) | Space: O(N)
    
    public static int countOddEvenPrefixSum(int[] nums) {
        /*
         * Transform: odd → +1, even → -1
         * Problem becomes: count subarrays with sum = 0
         */
        Map<Integer, Integer> prefixSumMap = new HashMap<>();
        prefixSumMap.put(0, 1);  // Empty prefix
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : nums) {
            // Transform: odd → +1, even → -1
            if (num % 2 == 1) {
                prefixSum += 1;
            } else {
                prefixSum -= 1;
            }
            
            // If this prefix sum seen before, all previous occurrences
            // form valid subarrays (sum = 0) with current position
            if (prefixSumMap.containsKey(prefixSum)) {
                count += prefixSumMap.get(prefixSum);
                prefixSumMap.put(prefixSum, prefixSumMap.get(prefixSum) + 1);
            } else {
                prefixSumMap.put(prefixSum, 1);
            }
        }
        
        return count;
    }
    
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    
    public static int countOddEvenSubarrays(int[] nums) {
        /*
         * Count subarrays with equal odd and even counts.
         * 
         * Time: O(N) - single pass
         * Space: O(N) - HashMap
         * 
         * Example:
         *     countOddEvenSubarrays([2, 5, 4, 6, 3, 1]) -> 6
         */
        return countOddEvenPrefixSum(nums);
    }
}
