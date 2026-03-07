import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(n³) | Space: O(m)
    public String minWindowBruteForce(String s, String t) {
        if (s.isEmpty() || t.isEmpty()) return "";
        
        Map<Character, Integer> tCount = new HashMap<>();
        for (char c : t.toCharArray()) {
            tCount.put(c, tCount.getOrDefault(c, 0) + 1);
        }
        
        String minWindow = "";
        int minLen = Integer.MAX_VALUE;
        
        // Check all substrings
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                String window = s.substring(i, j + 1);
                
                if (containsAll(window, tCount) && window.length() < minLen) {
                    minLen = window.length();
                    minWindow = window;
                }
            }
        }
        
        return minWindow;
    }
    
    private boolean containsAll(String window, Map<Character, Integer> tCount) {
        Map<Character, Integer> windowCount = new HashMap<>();
        for (char c : window.toCharArray()) {
            windowCount.put(c, windowCount.getOrDefault(c, 0) + 1);
        }
        
        for (Map.Entry<Character, Integer> entry : tCount.entrySet()) {
            if (windowCount.getOrDefault(entry.getKey(), 0) < entry.getValue()) {
                return false;
            }
        }
        return true;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAPS ====================
    // Time: O(n+m) | Space: O(m+k)
    public String minWindowSlidingWindow(String s, String t) {
        if (s.isEmpty() || t.isEmpty()) return "";
        
        Map<Character, Integer> tCount = new HashMap<>();
        for (char c : t.toCharArray()) {
            tCount.put(c, tCount.getOrDefault(c, 0) + 1);
        }
        
        Map<Character, Integer> windowCount = new HashMap<>();
        int left = 0;
        int minLen = Integer.MAX_VALUE;
        int minStart = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Add character to window
            char c = s.charAt(right);
            windowCount.put(c, windowCount.getOrDefault(c, 0) + 1);
            
            // Try to shrink window
            while (containsAllChars(windowCount, tCount)) {
                // Update minimum
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Shrink from left
                char leftChar = s.charAt(left);
                windowCount.put(leftChar, windowCount.get(leftChar) - 1);
                if (windowCount.get(leftChar) == 0) {
                    windowCount.remove(leftChar);
                }
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
    
    private boolean containsAllChars(Map<Character, Integer> window, Map<Character, Integer> t) {
        for (Map.Entry<Character, Integer> entry : t.entrySet()) {
            if (window.getOrDefault(entry.getKey(), 0) < entry.getValue()) {
                return false;
            }
        }
        return true;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED WITH MATCH COUNT ====================
    // Time: O(n+m) | Space: O(m+k)
    public String minWindowOptimized(String s, String t) {
        if (s.isEmpty() || t.isEmpty()) return "";
        
        Map<Character, Integer> tCount = new HashMap<>();
        for (char c : t.toCharArray()) {
            tCount.put(c, tCount.getOrDefault(c, 0) + 1);
        }
        
        int required = tCount.size();
        Map<Character, Integer> windowCount = new HashMap<>();
        int matched = 0;
        
        int left = 0;
        int minLen = Integer.MAX_VALUE;
        int minStart = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Add character to window
            char c = s.charAt(right);
            windowCount.put(c, windowCount.getOrDefault(c, 0) + 1);
            
            // Check if frequency matches
            if (tCount.containsKey(c) && windowCount.get(c).intValue() == tCount.get(c).intValue()) {
                matched++;
            }
            
            // Try to shrink window
            while (matched == required) {
                // Update minimum
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Shrink from left
                char leftChar = s.charAt(left);
                windowCount.put(leftChar, windowCount.get(leftChar) - 1);
                if (tCount.containsKey(leftChar) && windowCount.get(leftChar) < tCount.get(leftChar)) {
                    matched--;
                }
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public String minWindow(String s, String t) {
        return minWindowOptimized(s, t);
    }
}
