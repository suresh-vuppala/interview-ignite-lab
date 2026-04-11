// ============================================================
// Longest Substring with K Distinct Characters
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(N)
// ============================================================
class Solution1 {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            Map<Character,Integer> f = new HashMap<>();
            for (int j = i; j < s.length(); j++) {
                f.merge(s.charAt(j), 1, Integer::sum);
                if (f.size() > k) break;
                max = Math.max(max, j - i + 1);
            }
        }
        return max;
    }
}

// ============================================================
// Solution 2: Sliding Window (Optimal)
// Time: O(N) | Space: O(K)
// ============================================================
class Solution2 {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> freq = new HashMap<>();
        int left = 0, max = 0;
        for (int right = 0; right < s.length(); right++) {
            freq.merge(s.charAt(right), 1, Integer::sum);
            while (freq.size() > k) {
                char lc = s.charAt(left);
                freq.merge(lc, -1, Integer::sum);
                if (freq.get(lc) == 0) freq.remove(lc);
                left++;
            }
            max = Math.max(max, right - left + 1);
        }
        return max;
    }
}
