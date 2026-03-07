import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n³) | Space: O(n)
    public int minimumCardPickupBruteForce(int[] cards) {
        int n = cards.length;
        int minLen = Integer.MAX_VALUE;
        
        // Check all subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Check if subarray has duplicates
                Set<Integer> seen = new HashSet<>();
                boolean hasDuplicate = false;
                
                for (int k = i; k <= j; k++) {
                    if (seen.contains(cards[k])) {
                        hasDuplicate = true;
                        break;
                    }
                    seen.add(cards[k]);
                }
                
                if (hasDuplicate) {
                    minLen = Math.min(minLen, j - i + 1);
                }
            }
        }
        
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
    
    // ==================== SOLUTION 2: HASHMAP WITH LAST SEEN POSITION ====================
    // Time: O(n) | Space: O(n)
    public int minimumCardPickupHashMap(int[] cards) {
        Map<Integer, Integer> lastSeen = new HashMap<>();
        int minLen = Integer.MAX_VALUE;
        
        for (int i = 0; i < cards.length; i++) {
            int card = cards[i];
            
            // If card seen before, calculate distance
            if (lastSeen.containsKey(card)) {
                int distance = i - lastSeen.get(card) + 1;
                minLen = Math.min(minLen, distance);
            }
            
            // Update last seen position
            lastSeen.put(card, i);
        }
        
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
    
    // ==================== SOLUTION 3: SLIDING WINDOW ====================
    // Time: O(n) | Space: O(n)
    public int minimumCardPickupSlidingWindow(int[] cards) {
        Map<Integer, Integer> window = new HashMap<>();
        int left = 0;
        int minLen = Integer.MAX_VALUE;
        
        for (int right = 0; right < cards.length; right++) {
            int card = cards[right];
            
            // If card already in window, we found a pair
            if (window.containsKey(card)) {
                // Update minimum length
                minLen = Math.min(minLen, right - window.get(card) + 1);
                
                // Shrink window from left until duplicate removed
                while (cards[left] != card) {
                    window.remove(cards[left]);
                    left++;
                }
                
                // Remove the duplicate from left
                window.remove(cards[left]);
                left++;
            }
            
            // Add card to window
            window.put(card, right);
        }
        
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public int minimumCardPickup(int[] cards) {
        return minimumCardPickupHashMap(cards);
    }
}
