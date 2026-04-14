// ============================================================
// Solution 1: HashSet — O(N³) generate all substrings
// ============================================================
import java.util.*;
class Solution1 {
    public int countDistinct(String s) {
        Set<String> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++)
            for (int j = i + 1; j <= s.length(); j++)
                set.add(s.substring(i, j));
        return set.size();
    }
}

// ============================================================
// Solution 2: Suffix Trie — O(N²) insert suffixes, count nodes
// ============================================================
class Solution2 {
    public int countDistinct(String s) {
        int[][] ch = new int[s.length() * s.length() + 1][26];
        int cnt = 0, count = 0;
        for (int i = 0; i < s.length(); i++) {
            int node = 0;
            for (int j = i; j < s.length(); j++) {
                int idx = s.charAt(j) - 'a';
                if (ch[node][idx] == 0) { ch[node][idx] = ++cnt; count++; }
                node = ch[node][idx];
            }
        }
        return count;
    }
}
