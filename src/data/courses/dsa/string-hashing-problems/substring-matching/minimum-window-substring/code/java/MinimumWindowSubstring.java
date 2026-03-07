// Time: O(N^3+N^2*M) brute, O(N+M) sliding window, O(N*M*log(N)) binary search
// Space: O(M)

import java.util.*;

class MinimumWindowSubstring {
    // Solution 1: Brute Force
    public String bruteForce(String s, String t) {
        if (s.length() == 0 || t.length() == 0 || t.length() > s.length()) {
            return "";
        }
        
        Map<Character, Integer> target = new HashMap<>();
        for (char c : t.toCharArray()) {
            target.put(c, target.getOrDefault(c, 0) + 1);
        }
        
        int minLen = Integer.MAX_VALUE;
        String result = "";
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                Map<Character, Integer> window = new HashMap<>();
                for (int k = i; k <= j; k++) {
                    char c = s.charAt(k);
                    window.put(c, window.getOrDefault(c, 0) + 1);
                }
                
                boolean valid = true;
                for (char c : target.keySet()) {
                    if (window.getOrDefault(c, 0) < target.get(c)) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid && j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    result = s.substring(i, j + 1);
                }
            }
        }
        
        return result;
    }
    
    // Solution 2: Sliding Window (Optimal)
    public String slidingWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0 || t.length() > s.length()) {
            return "";
        }
        
        Map<Character, Integer> target = new HashMap<>();
        for (char c : t.toCharArray()) {
            target.put(c, target.getOrDefault(c, 0) + 1);
        }
        
        Map<Character, Integer> window = new HashMap<>();
        int required = target.size();
        int formed = 0;
        
        int left = 0;
        int minLen = Integer.MAX_VALUE;
        String result = "";
        
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            window.put(c, window.getOrDefault(c, 0) + 1);
            
            if (target.containsKey(c) && window.get(c).intValue() == target.get(c).intValue()) {
                formed++;
            }
            
            while (formed == required && left <= right) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    result = s.substring(left, right + 1);
                }
                
                char leftChar = s.charAt(left);
                window.put(leftChar, window.get(leftChar) - 1);
                if (target.containsKey(leftChar) && window.get(leftChar) < target.get(leftChar)) {
                    formed--;
                }
                left++;
            }
        }
        
        return result;
    }
    
    // Solution 3: Binary Search on Length
    public String binarySearch(String s, String t) {
        if (s.length() == 0 || t.length() == 0 || t.length() > s.length()) {
            return "";
        }
        
        Map<Character, Integer> target = new HashMap<>();
        for (char c : t.toCharArray()) {
            target.put(c, target.getOrDefault(c, 0) + 1);
        }
        
        int left = t.length(), right = s.length();
        String result = "";
        
        while (left <= right) {
            int mid = (left + right) / 2;
            String window = hasValidWindow(s, target, mid);
            if (window != null) {
                result = window;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    private String hasValidWindow(String s, Map<Character, Integer> target, int length) {
        for (int i = 0; i <= s.length() - length; i++) {
            Map<Character, Integer> window = new HashMap<>();
            for (int j = i; j < i + length; j++) {
                char c = s.charAt(j);
                window.put(c, window.getOrDefault(c, 0) + 1);
            }
            
            boolean valid = true;
            for (char c : target.keySet()) {
                if (window.getOrDefault(c, 0) < target.get(c)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                return s.substring(i, i + length);
            }
        }
        return null;
    }
}
