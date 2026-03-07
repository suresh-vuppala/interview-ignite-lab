import java.util.*;

public class MajorityElement {
    
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N²) | Space: O(1)
    
    public static int majorityElementBrute(int[] nums) {
        int n = nums.length;
        for (int num : nums) {
            int count = 0;
            for (int x : nums) {
                if (x == num) count++;
            }
            if (count > n / 2) {
                return num;
            }
        }
        return -1;
    }
    
    
    // ==================== SOLUTION 2: HASHMAP ====================
    // Time: O(N) | Space: O(N)
    
    public static int majorityElementHashMap(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> freq = new HashMap<>();
        
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
            if (freq.get(num) > n / 2) {
                return num;
            }
        }
        
        return -1;
    }
    
    
    // ==================== SOLUTION 3: SORTING ====================
    // Time: O(N log N) | Space: O(1) or O(N)
    
    public static int majorityElementSorting(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
    
    
    // ==================== SOLUTION 4: BOYER-MOORE VOTING ====================
    // Time: O(N) | Space: O(1)
    
    public static int majorityElementBoyerMoore(int[] nums) {
        /*
         * Boyer-Moore Voting Algorithm.
         * 
         * Maintain candidate and count. Cancel out different elements.
         * Final candidate is the majority element.
         */
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
    
    
    // ==================== SOLUTION 5: RANDOMIZED ====================
    // Time: O(N) expected | Space: O(1)
    
    public static int majorityElementRandomized(int[] nums) {
        int n = nums.length;
        Random rand = new Random();
        
        while (true) {
            int candidate = nums[rand.nextInt(n)];
            int count = 0;
            for (int num : nums) {
                if (num == candidate) count++;
            }
            if (count > n / 2) {
                return candidate;
            }
        }
    }
    
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    
    public static int majorityElement(int[] nums) {
        /*
         * Find the majority element (appears > n/2 times).
         * 
         * Time: O(N) - single pass
         * Space: O(1) - only two variables
         * 
         * Uses Boyer-Moore Voting Algorithm - optimal solution.
         * 
         * Example:
         *     majorityElement([3, 2, 3]) -> 3
         *     majorityElement([2, 2, 1, 1, 1, 2, 2]) -> 2
         */
        return majorityElementBoyerMoore(nums);
    }
}
