// ============================================================
// Isomorphic Strings
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Two Hash Maps (Bidirectional)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> mapST = new HashMap<>();
        Map<Character, Character> mapTS = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char sc = s.charAt(i), tc = t.charAt(i);

            if (mapST.containsKey(sc) && mapST.get(sc) != tc) return false;
            if (mapTS.containsKey(tc) && mapTS.get(tc) != sc) return false;

            mapST.put(sc, tc);
            mapTS.put(tc, sc);
        }

        return true;
    }
}

// ============================================================
// Solution 2: First Occurrence Pattern Encoding
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
    public boolean isIsomorphic(String s, String t) {
        return encode(s).equals(encode(t));
    }

    private List<Integer> encode(String str) {
        Map<Character, Integer> first = new HashMap<>();
        List<Integer> pattern = new ArrayList<>();

        for (int i = 0; i < str.length(); i++) {
            first.putIfAbsent(str.charAt(i), i);
            pattern.add(first.get(str.charAt(i)));
        }

        return pattern;
    }
}
