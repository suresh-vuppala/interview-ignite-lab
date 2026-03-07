import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n²) | Space: O(n)
    public int totalFruitBruteForce(int[] fruits) {
        int n = fruits.length;
        int maxFruits = 0;
        
        // Check all subarrays
        for (int i = 0; i < n; i++) {
            Set<Integer> types = new HashSet<>();
            for (int j = i; j < n; j++) {
                types.add(fruits[j]);
                
                // Check if valid (at most 2 types)
                if (types.size() <= 2) {
                    maxFruits = Math.max(maxFruits, j - i + 1);
                } else {
                    break;  // More than 2 types
                }
            }
        }
        
        return maxFruits;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH HASHMAP ====================
    // Time: O(n) | Space: O(1)
    public int totalFruitSlidingWindow(int[] fruits) {
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0;
        int maxFruits = 0;
        
        for (int right = 0; right < fruits.length; right++) {
            // Add fruit to window
            freq.put(fruits[right], freq.getOrDefault(fruits[right], 0) + 1);
            
            // Shrink window while more than 2 types
            while (freq.size() > 2) {
                freq.put(fruits[left], freq.get(fruits[left]) - 1);
                if (freq.get(fruits[left]) == 0) {
                    freq.remove(fruits[left]);
                }
                left++;
            }
            
            // Update max fruits
            maxFruits = Math.max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    // Time: O(n) | Space: O(1)
    public int totalFruitOptimized(int[] fruits) {
        Map<Integer, Integer> freq = new HashMap<>();
        int left = 0;
        
        for (int right = 0; right < fruits.length; right++) {
            // Add fruit to window
            freq.put(fruits[right], freq.getOrDefault(fruits[right], 0) + 1);
            
            // If more than 2 types, slide window
            if (freq.size() > 2) {
                freq.put(fruits[left], freq.get(fruits[left]) - 1);
                if (freq.get(fruits[left]) == 0) {
                    freq.remove(fruits[left]);
                }
                left++;
            }
        }
        
        // Window size is the answer
        return fruits.length - left;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public int totalFruit(int[] fruits) {
        return totalFruitSlidingWindow(fruits);
    }
}
