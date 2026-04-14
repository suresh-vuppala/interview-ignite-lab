// ============================================================
// Solution 1: Brute Force Recursion — O(2^N)
// ============================================================
import java.util.*;
class Solution1 {
    public boolean wordBreak(String s, List<String> wordDict) {
        return canBreak(s, 0, new HashSet<>(wordDict));
    }
    boolean canBreak(String s, int start, Set<String> dict) {
        if (start == s.length()) return true;
        for (int end = start+1; end <= s.length(); end++)
            if (dict.contains(s.substring(start, end)) && canBreak(s, end, dict)) return true;
        return false;
    }
}

// ============================================================
// Solution 2: Trie + DP — O(N*L)
// ============================================================
class Solution2 {
    int[][] ch = new int[100001][26]; boolean[] isEnd = new boolean[100001]; int cnt = 0;
    void insert(String w) { int n=0; for(char c:w.toCharArray()){if(ch[n][c-'a']==0)ch[n][c-'a']=++cnt;n=ch[n][c-'a'];}isEnd[n]=true; }
    public boolean wordBreak(String s, List<String> wordDict) {
        for (String w : wordDict) insert(w);
        boolean[] dp = new boolean[s.length()+1]; dp[0] = true;
        for (int i = 0; i < s.length(); i++) {
            if (!dp[i]) continue;
            int node = 0;
            for (int j = i; j < s.length(); j++) {
                if (ch[node][s.charAt(j)-'a']==0) break;
                node = ch[node][s.charAt(j)-'a'];
                if (isEnd[node]) dp[j+1] = true;
            }
        }
        return dp[s.length()];
    }
}
