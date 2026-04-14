// ============================================================
// Solution 1: HashSet — Check all prefixes O(W*L²)
// ============================================================
import java.util.*;
class Solution1 {
    public String replaceWords(List<String> dict, String sentence) {
        Set<String> roots = new HashSet<>(dict);
        StringBuilder sb = new StringBuilder();
        for (String word : sentence.split(" ")) {
            String rep = word;
            for (int i = 1; i <= word.length(); i++) {
                if (roots.contains(word.substring(0, i))) { rep = word.substring(0, i); break; }
            }
            if (sb.length() > 0) sb.append(" ");
            sb.append(rep);
        }
        return sb.toString();
    }
}

// ============================================================
// Solution 2: Trie — O(L) prefix match per word
// ============================================================
class Solution2 {
    int[][] ch = new int[100001][26]; boolean[] isEnd = new boolean[100001]; int cnt = 0;
    void insert(String s) { int n=0; for (char c:s.toCharArray()) { if(ch[n][c-'a']==0) ch[n][c-'a']=++cnt; n=ch[n][c-'a']; } isEnd[n]=true; }
    String find(String w) { int n=0; for (int i=0;i<w.length();i++) { if(ch[n][w.charAt(i)-'a']==0) break; n=ch[n][w.charAt(i)-'a']; if(isEnd[n]) return w.substring(0,i+1); } return w; }
    public String replaceWords(List<String> dict, String sentence) {
        for (String d:dict) insert(d);
        StringBuilder sb = new StringBuilder();
        for (String w : sentence.split(" ")) { if(sb.length()>0) sb.append(" "); sb.append(find(w)); }
        return sb.toString();
    }
}
