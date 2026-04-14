// ============================================================
// Solution 1: DFS per word — O(W*M*N*4^L)
// ============================================================
import java.util.*;
class Solution1 {
    int m, n;
    boolean dfs(char[][] b, String w, int i, int r, int c) {
        if (i==w.length()) return true;
        if (r<0||r>=m||c<0||c>=n||b[r][c]!=w.charAt(i)) return false;
        char t=b[r][c]; b[r][c]='#';
        boolean f=dfs(b,w,i+1,r+1,c)||dfs(b,w,i+1,r-1,c)||dfs(b,w,i+1,r,c+1)||dfs(b,w,i+1,r,c-1);
        b[r][c]=t; return f;
    }
    public List<String> findWords(char[][] board, String[] words) {
        m=board.length; n=board[0].length; List<String> res=new ArrayList<>();
        for (String w:words) { boolean found=false;
            for (int r=0;r<m&&!found;r++) for (int c=0;c<n&&!found;c++) if (dfs(board,w,0,r,c)) found=true;
            if (found) res.add(w); }
        return res;
    }
}

// ============================================================
// Solution 2: Trie + single DFS — O(M*N*4^L)
// ============================================================
class Solution2 {
    int[][] ch=new int[250001][26]; String[] word=new String[250001]; int cnt=0;
    int m,n; List<String> res=new ArrayList<>();
    void dfs(char[][] b,int r,int c,int node) {
        if(r<0||r>=m||c<0||c>=n||b[r][c]=='#') return;
        int idx=b[r][c]-'a'; int next=ch[node][idx]; if(next==0) return;
        if(word[next]!=null){res.add(word[next]);word[next]=null;}
        char t=b[r][c];b[r][c]='#';
        dfs(b,r+1,c,next);dfs(b,r-1,c,next);dfs(b,r,c+1,next);dfs(b,r,c-1,next);
        b[r][c]=t;
    }
    public List<String> findWords(char[][] board, String[] words) {
        for(String w:words){int n=0;for(char c:w.toCharArray()){if(ch[n][c-'a']==0)ch[n][c-'a']=++cnt;n=ch[n][c-'a'];}word[n]=w;}
        m=board.length;n=board[0].length;
        for(int r=0;r<m;r++) for(int c=0;c<n;c++) dfs(board,r,c,0);
        return res;
    }
}
