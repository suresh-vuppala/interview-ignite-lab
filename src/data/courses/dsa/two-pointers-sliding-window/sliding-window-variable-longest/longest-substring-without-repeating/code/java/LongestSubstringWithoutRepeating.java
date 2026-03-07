public class LongestSubstringWithoutRepeating {
    // ==================== SOLUTION 1: BRUTE FORCE ====================
    // Time: O(N³) | Space: O(min(N, M))
    public int lengthOfLongestSubstringBruteForce(String s) {
        int n = s.length();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (allUnique(s, i, j)) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
    
    private boolean allUnique(String s, int start, int end) {
        Set<Character> charSet = new HashSet<>();
        for (int i = start; i <= end; i++) {
            if (charSet.contains(s.charAt(i))) {
                return false;
            }
            charSet.add(s.charAt(i));
        }
        return true;
    }
    
    // ==================== SOLUTION 2: BRUTE FORCE OPTIMIZED ====================
    // Time: O(N²) | Space: O(min(N, M))
    public int lengthOfLongestSubstringBruteOptimized(String s) {
        int n = s.length();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            Set<Character> charSet = new HashSet<>();
            for (int j = i; j < n; j++) {
                if (charSet.contains(s.charAt(j))) {
                    break;
                }
                charSet.add(s.charAt(j));
                maxLen = Math.max(maxLen, j - i + 1);
            }
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 3: SLIDING WINDOW (TWO POINTERS) ====================
    // Time: O(2N) = O(N) | Space: O(min(N, M))
    public int lengthOfLongestSubstringSlidingWindow(String s) {
        int n = s.length();
        Set<Character> charSet = new HashSet<>();
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            while (charSet.contains(s.charAt(right))) {
                charSet.remove(s.charAt(left));
                left++;
            }
            charSet.add(s.charAt(right));
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 4: SLIDING WINDOW WITH HASHMAP ====================
    // Time: O(N) | Space: O(min(N, M))
    public int lengthOfLongestSubstringHashMap(String s) {
        int n = s.length();
        Map<Character, Integer> charMap = new HashMap<>();
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.containsKey(s.charAt(right))) {
                left = Math.max(left, charMap.get(s.charAt(right)) + 1);
            }
            charMap.put(s.charAt(right), right);
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
    
    // ==================== SOLUTION 5: OPTIMIZED WITH ARRAY (ASCII) - OPTIMAL ====================
    // Time: O(N) | Space: O(1)
    public int lengthOfLongestSubstring(String s) {
        int[] charIndex = new int[128];
        Arrays.fill(charIndex, -1);
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charIndex[s.charAt(right)] >= left) {
                left = charIndex[s.charAt(right)] + 1;
            }
            charIndex[s.charAt(right)] = right;
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
}
