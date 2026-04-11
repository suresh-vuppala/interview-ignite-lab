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
        // Omitted for brevity — same logic as C++
        return "";
    }
}

// ============================================================
// Solution 2: Sliding Window + Frequency Tracking (Optimal)
// Time: O(N+M) | Space: O(N+M)
// ============================================================
class Solution2 {
    public String minWindow(String s, String t) {
        Map<Character, Integer> tFreq = new HashMap<>(), wFreq = new HashMap<>();
        for (char c : t.toCharArray()) tFreq.merge(c, 1, Integer::sum);

        int required = tFreq.size(), formed = 0;
        int left = 0, minLen = Integer.MAX_VALUE, minStart = 0;

        for (int right = 0; right < s.length(); right++) {
            char rc = s.charAt(right);
            wFreq.merge(rc, 1, Integer::sum);

            if (tFreq.containsKey(rc) && wFreq.get(rc).equals(tFreq.get(rc)))
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char lc = s.charAt(left);
                wFreq.merge(lc, -1, Integer::sum);
                if (tFreq.containsKey(lc) && wFreq.get(lc) < tFreq.get(lc))
                    formed--;
                left++;
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
}
