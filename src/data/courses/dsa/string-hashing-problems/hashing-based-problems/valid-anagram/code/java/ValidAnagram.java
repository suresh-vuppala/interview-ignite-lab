// ============================================================
// Valid Anagram
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Sort Both Strings
// Time: O(N log N) | Space: O(N)
// ============================================================
class Solution1 {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        char[] a = s.toCharArray(), b = t.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);

        return Arrays.equals(a, b);
    }
}

// ============================================================
// Solution 2: Frequency Count Array (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        int[] freq = new int[26];

        for (char c : s.toCharArray()) freq[c - 'a']++;
        for (char c : t.toCharArray()) freq[c - 'a']--;

        for (int f : freq) {
            if (f != 0) return false;
        }

        return true;
    }
}
