import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n²) | Space: O(1)
    public int characterReplacementBruteForce(String s, int k) {
        int n = s.length();
        int maxLen = 0;
        
        // Check all substrings
        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];
            for (int j = i; j < n; j++) {
                // Update frequency
                freq[s.charAt(j) - 'A']++;
                
                // Find max frequency
                int maxFreq = 0;
                for (int f : freq) {
                    maxFreq = Math.max(maxFreq, f);
                }
                
                int length = j - i + 1;
                
                // Check if valid
                if (length - maxFreq <= k) {
                    maxLen = Math.max(maxLen, length);
                }
            }
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAP ====================
    // Time: O(n×26) = O(n) | Space: O(1)
    public int characterReplacementSlidingWindow(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            // Add character to window
            freq[s.charAt(right) - 'A']++;
            
            // Find max frequency
            int maxFreq = 0;
            for (int f : freq) {
                maxFreq = Math.max(maxFreq, f);
            }
            
            // Shrink window if invalid
            while ((right - left + 1) - maxFreq > k) {
                freq[s.charAt(left) - 'A']--;
                left++;
            }
            
            // Update max length
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED SLIDING WINDOW ====================
    // Time: O(n) | Space: O(1)
    public int characterReplacementOptimized(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;
        
        for (int right = 0; right < n; right++) {
            // Add character to window
            freq[s.charAt(right) - 'A']++;
            
            // Update max frequency
            maxFreq = Math.max(maxFreq, freq[s.charAt(right) - 'A']);
            
            // Shrink window if invalid
            while ((right - left + 1) - maxFreq > k) {
                freq[s.charAt(left) - 'A']--;
                left++;
            }
            
            // Update max length
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public int characterReplacement(String s, int k) {
        return characterReplacementOptimized(s, k);
    }
}
