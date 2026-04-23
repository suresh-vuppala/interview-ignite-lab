// ============================================================
// Minimum Window Substring
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²×M) | Space: O(M)
// ============================================================
class Solution1 {
    public String minWindow(String s, String t) {
        // Build frequency map for target string t
        Map<Character, Integer> targetFreq = new HashMap<>();
        for (char c : t.toCharArray()) {
            targetFreq.put(c, targetFreq.getOrDefault(c, 0) + 1);
        }
        
        int minLength = Integer.MAX_VALUE;
        int minStart = 0;
        
        // Try all possible substrings
        for (int start = 0; start < s.length(); start++) {
            Map<Character, Integer> windowFreq = new HashMap<>();
            
            for (int end = start; end < s.length(); end++) {
                // Add current character to window
                char c = s.charAt(end);
                windowFreq.put(c, windowFreq.getOrDefault(c, 0) + 1);
                
                // Check if current window contains all characters of t
                boolean isValid = true;
                for (Map.Entry<Character, Integer> entry : targetFreq.entrySet()) {
                    if (windowFreq.getOrDefault(entry.getKey(), 0) < entry.getValue()) {
                        isValid = false;
                        break;
                    }
                }
                
                // Update minimum window if valid and smaller
                if (isValid && end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    minStart = start;
                    break; // No need to expand further from this start
                }
            }
        }
        
        return minLength == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLength);
    }
}

// ============================================================
// Solution 2: Sliding Window + Frequency Tracking (Optimal)
// Time: O(N+M) | Space: O(N+M)
// ============================================================
class Solution2 {
    public String minWindow(String s, String t) {
        // Step 1: Build frequency map for target string t
        Map<Character, Integer> targetFreq = new HashMap<>();
        for (char c : t.toCharArray()) {
            targetFreq.put(c, targetFreq.getOrDefault(c, 0) + 1);
        }
        
        // Step 2: Initialize variables
        int required = targetFreq.size();  // Number of unique chars in t that need to be present
        int formed = 0;                     // Number of unique chars in current window with desired frequency
        
        Map<Character, Integer> windowFreq = new HashMap<>(); // Frequency map for current window
        
        int left = 0;                       // Left pointer of sliding window
        int minLength = Integer.MAX_VALUE;  // Length of minimum window found
        int minStart = 0;                   // Start index of minimum window
        
        // Step 3: Expand window by moving right pointer
        for (int right = 0; right < s.length(); right++) {
            char rightChar = s.charAt(right);
            
            // Add character from right to window
            windowFreq.put(rightChar, windowFreq.getOrDefault(rightChar, 0) + 1);
            
            // Check if frequency of current character matches the desired count in t
            if (targetFreq.containsKey(rightChar) && 
                windowFreq.get(rightChar).equals(targetFreq.get(rightChar))) {
                formed++; // One more unique character requirement satisfied
            }
            
            // Step 4: Try to shrink window from left while it's still valid
            while (formed == required) {
                // Update minimum window if current is smaller
                int currentLength = right - left + 1;
                if (currentLength < minLength) {
                    minLength = currentLength;
                    minStart = left;
                }
                
                // Remove character from left of window
                char leftChar = s.charAt(left);
                windowFreq.put(leftChar, windowFreq.get(leftChar) - 1);
                
                // Check if removing this character breaks a requirement
                if (targetFreq.containsKey(leftChar) && 
                    windowFreq.get(leftChar) < targetFreq.get(leftChar)) {
                    formed--; // One unique character requirement no longer satisfied
                }
                
                left++; // Shrink window from left
            }
        }
        
        // Step 5: Return result
        return minLength == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLength);
    }
}

// ============================================================
// Solution 3: Binary Search on Length + Sliding Window
// Time: O(N×log N) | Space: O(N+M)
// ============================================================
class Solution3 {
    // Helper: Check if any window of given length contains all chars of t
    private int canFindWindow(String s, String t, int windowLen) {
        // Build target frequency map
        Map<Character, Integer> targetFreq = new HashMap<>();
        for (char c : t.toCharArray()) {
            targetFreq.put(c, targetFreq.getOrDefault(c, 0) + 1);
        }
        
        Map<Character, Integer> windowFreq = new HashMap<>();
        int required = targetFreq.size();
        int formed = 0;
        
        // Initialize first window
        for (int i = 0; i < windowLen && i < s.length(); i++) {
            char c = s.charAt(i);
            windowFreq.put(c, windowFreq.getOrDefault(c, 0) + 1);
            if (targetFreq.containsKey(c) && 
                windowFreq.get(c).equals(targetFreq.get(c))) {
                formed++;
            }
        }
        
        // Check first window
        if (formed == required) {
            return 0;
        }
        
        // Slide window across string
        for (int right = windowLen; right < s.length(); right++) {
            int left = right - windowLen;
            
            // Add new character on right
            char rightChar = s.charAt(right);
            windowFreq.put(rightChar, windowFreq.getOrDefault(rightChar, 0) + 1);
            if (targetFreq.containsKey(rightChar) && 
                windowFreq.get(rightChar).equals(targetFreq.get(rightChar))) {
                formed++;
            }
            
            // Remove character on left
            char leftChar = s.charAt(left);
            if (targetFreq.containsKey(leftChar) && 
                windowFreq.get(leftChar).equals(targetFreq.get(leftChar))) {
                formed--;
            }
            windowFreq.put(leftChar, windowFreq.get(leftChar) - 1);
            
            // Check if current window is valid
            if (formed == required) {
                return left + 1;
            }
        }
        
        return -1; // No valid window found
    }
    
    public String minWindow(String s, String t) {
        if (s.length() < t.length()) return "";
        
        // Binary search on window length
        int low = t.length();
        int high = s.length();
        int minLength = Integer.MAX_VALUE;
        int minStart = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if window of length mid exists
            int start = canFindWindow(s, t, mid);
            if (start != -1) {
                // Found valid window, try smaller length
                minLength = mid;
                minStart = start;
                high = mid - 1;
            } else {
                // Need larger window
                low = mid + 1;
            }
        }
        
        return minLength == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLength);
    }
}
