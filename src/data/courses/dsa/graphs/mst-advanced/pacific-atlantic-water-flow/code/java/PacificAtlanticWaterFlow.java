// ============================================================
// Pacific Atlantic Water Flow
// ============================================================
import java.util.*;
class Solution {
    int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    public List<List<Integer>> pacificAtlantic(int[][] h) {
        int m=h.length, n=h[0].length;
        boolean[][] pac=new boolean[m][n], atl=new boolean[m][n];
        for (int i=0;i<m;i++){dfs(h,pac,i,0);dfs(h,atl,i,n-1);}
        for (int j=0;j<n;j++){dfs(h,pac,0,j);dfs(h,atl,m-1,j);}
        List<List<Integer>> res = new ArrayList<>();
        for (int i=0;i<m;i++) for (int j=0;j<n;j++)
            if (pac[i][j]&&atl[i][j]) res.add(List.of(i,j));
        return res;
    }
    void dfs(int[][] h, boolean[][] vis, int i, int j) {
        vis[i][j] = true;
        for (int[] d:dirs){int ni=i+d[0],nj=j+d[1];
            if(ni>=0&&ni<h.length&&nj>=0&&nj<h[0].length&&!vis[ni][nj]&&h[ni][nj]>=h[i][j])dfs(h,vis,ni,nj);}
    }
}
