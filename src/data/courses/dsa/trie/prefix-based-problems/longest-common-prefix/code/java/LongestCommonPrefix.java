// ============================================================
// Solution 1: Vertical Scanning — O(N*L) time, O(1) space
// ============================================================
import java.util.*;

class Solution1 {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++)
                if (i >= strs[j].length() || strs[j].charAt(i) != c)
                    return strs[0].substring(0, i);
        }
        return strs[0];
    }
}

// ============================================================
// Solution 2: Trie — Insert all, walk single-child path
// ============================================================
class Solution2 {
    int[][] children = new int[100001][26];
    int[] childCount = new int[100001];
    boolean[] isEnd = new boolean[100001];
    int cnt = 0;

    int newNode() { cnt++; return cnt; }

    public String longestCommonPrefix(String[] strs) {
        cnt = 0; int root = newNode();
        for (String s : strs) {
            int node = root;
            for (char c : s.toCharArray()) {
                int idx = c - 'a';
                if (children[node][idx] == 0) { children[node][idx] = newNode(); childCount[node]++; }
                node = children[node][idx];
            }
            isEnd[node] = true;
        }
        StringBuilder sb = new StringBuilder();
        int node = root;
        while (childCount[node] == 1 && !isEnd[node]) {
            for (int i = 0; i < 26; i++)
                if (children[node][i] != 0) { sb.append((char)('a'+i)); node = children[node][i]; break; }
        }
        return sb.toString();
    }
}
