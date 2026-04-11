// ============================================================
// Find All Anagrams in a String
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Brute Force
// Time: O(N×M) | Space: O(1)
// ============================================================
class Solution1 {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        int m = p.length();
        int[] pf = new int[26];
        for (char c : p.toCharArray()) pf[c - 'a']++;

        for (int i = 0; i <= s.length() - m; i++) {
            int[] wf = new int[26];
            for (int j = i; j < i + m; j++) wf[s.charAt(j) - 'a']++;
            if (Arrays.equals(wf, pf)) result.add(i);
        }
        return result;
    }
}

// ============================================================
// Solution 2: Sliding Window + Frequency Match (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if (s.length() < p.length()) return result;

        int[] pf = new int[26], wf = new int[26];
        int m = p.length();
        for (char c : p.toCharArray()) pf[c - 'a']++;

        for (int i = 0; i < s.length(); i++) {
            wf[s.charAt(i) - 'a']++;
            if (i >= m) wf[s.charAt(i - m) - 'a']--;
            if (i >= m - 1 && Arrays.equals(wf, pf))
                result.add(i - m + 1);
        }
        return result;
    }
}
