import java.util.*;

class Solution {
    // ==================== SOLUTION 1: BRUTE FORCE WITH SORTING ====================
    // Time: O(n×k log k) | Space: O(k)
    public List<Integer> findAnagramsBruteForce(String s, String p) {
        List<Integer> result = new ArrayList<>();
        int k = p.length();
        int n = s.length();
        char[] sortedP = p.toCharArray();
        Arrays.sort(sortedP);
        
        // Check each window
        for (int i = 0; i <= n - k; i++) {
            char[] window = s.substring(i, i + k).toCharArray();
            Arrays.sort(window);
            if (Arrays.equals(window, sortedP)) {
                result.add(i);
            }
        }
        
        return result;
    }
    
    // ==================== SOLUTION 2: SLIDING WINDOW WITH FREQUENCY MAP ====================
    // Time: O(n) | Space: O(1)
    public List<Integer> findAnagramsFreqMap(String s, String p) {
        List<Integer> result = new ArrayList<>();
        int k = p.length();
        int n = s.length();
        
        if (n < k) return result;
        
        // Build frequency maps
        Map<Character, Integer> pCount = new HashMap<>();
        Map<Character, Integer> windowCount = new HashMap<>();
        
        for (char c : p.toCharArray()) {
            pCount.put(c, pCount.getOrDefault(c, 0) + 1);
        }
        
        // First window
        for (int i = 0; i < k; i++) {
            char c = s.charAt(i);
            windowCount.put(c, windowCount.getOrDefault(c, 0) + 1);
        }
        
        // Check first window
        if (windowCount.equals(pCount)) {
            result.add(0);
        }
        
        // Slide window
        for (int i = k; i < n; i++) {
            // Add new character
            char newChar = s.charAt(i);
            windowCount.put(newChar, windowCount.getOrDefault(newChar, 0) + 1);
            
            // Remove old character
            char oldChar = s.charAt(i - k);
            windowCount.put(oldChar, windowCount.get(oldChar) - 1);
            if (windowCount.get(oldChar) == 0) {
                windowCount.remove(oldChar);
            }
            
            // Check if anagram
            if (windowCount.equals(pCount)) {
                result.add(i - k + 1);
            }
        }
        
        return result;
    }
    
    // ==================== SOLUTION 3: OPTIMIZED WITH MATCH COUNT ====================
    // Time: O(n) | Space: O(1)
    public List<Integer> findAnagramsOptimized(String s, String p) {
        List<Integer> result = new ArrayList<>();
        int k = p.length();
        int n = s.length();
        
        if (n < k) return result;
        
        // Frequency arrays for lowercase letters
        int[] pCount = new int[26];
        int[] windowCount = new int[26];
        
        // Build pattern frequency
        for (char c : p.toCharArray()) {
            pCount[c - 'a']++;
        }
        
        // Build first window
        for (int i = 0; i < k; i++) {
            windowCount[s.charAt(i) - 'a']++;
        }
        
        // Count initial matches
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (pCount[i] == windowCount[i]) {
                matches++;
            }
        }
        
        if (matches == 26) {
            result.add(0);
        }
        
        // Slide window
        for (int i = k; i < n; i++) {
            // Add new character
            int newIdx = s.charAt(i) - 'a';
            windowCount[newIdx]++;
            if (windowCount[newIdx] == pCount[newIdx]) {
                matches++;
            } else if (windowCount[newIdx] == pCount[newIdx] + 1) {
                matches--;
            }
            
            // Remove old character
            int oldIdx = s.charAt(i - k) - 'a';
            windowCount[oldIdx]--;
            if (windowCount[oldIdx] == pCount[oldIdx]) {
                matches++;
            } else if (windowCount[oldIdx] == pCount[oldIdx] - 1) {
                matches--;
            }
            
            // Check if all match
            if (matches == 26) {
                result.add(i - k + 1);
            }
        }
        
        return result;
    }
    
    // ==================== MAIN SOLUTION (RECOMMENDED) ====================
    public List<Integer> findAnagrams(String s, String p) {
        return findAnagramsOptimized(s, p);
    }
}
