// ============================================================
// Group Anagrams
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Sort Each String as Key
// Time: O(N × K log K) | Space: O(N × K)
// ============================================================
class Solution1 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> groups = new HashMap<>();

        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);

            groups.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(groups.values());
    }
}

// ============================================================
// Solution 2: Character Frequency Count as Key (Optimal)
// Time: O(N × K) | Space: O(N × K)
// ============================================================
class Solution2 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> groups = new HashMap<>();

        for (String s : strs) {
            int[] freq = new int[26];
            for (char c : s.toCharArray()) freq[c - 'a']++;

            // Build frequency key
            StringBuilder sb = new StringBuilder();
            for (int f : freq) sb.append(f).append('#');
            String key = sb.toString();

            groups.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }

        return new ArrayList<>(groups.values());
    }
}
