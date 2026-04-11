// ============================================================
// Longest Substring Without Repeating Characters
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N³) | Space: O(N)
// ============================================================
class Solution1 {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            Set<Character> seen = new HashSet<>();
            for (int j = i; j < s.length(); j++) {
                if (!seen.add(s.charAt(j))) break;
                max = Math.max(max, j - i + 1);
            }
        }
        return max;
    }
}

// ============================================================
// Solution 2: Sliding Window + Hash Set
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> window = new HashSet<>();
        int left = 0, max = 0;
        for (int right = 0; right < s.length(); right++) {
            while (window.contains(s.charAt(right))) {
                window.remove(s.charAt(left++));
            }
            window.add(s.charAt(right));
            max = Math.max(max, right - left + 1);
        }
        return max;
    }
}

// ============================================================
// Solution 3: Last Index Map (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution3 {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> last = new HashMap<>();
        int left = 0, max = 0;
        for (int right = 0; right < s.length(); right++) {
            if (last.containsKey(s.charAt(right)) && last.get(s.charAt(right)) >= left) {
                left = last.get(s.charAt(right)) + 1;
            }
            last.put(s.charAt(right), right);
            max = Math.max(max, right - left + 1);
        }
        return max;
    }
}
