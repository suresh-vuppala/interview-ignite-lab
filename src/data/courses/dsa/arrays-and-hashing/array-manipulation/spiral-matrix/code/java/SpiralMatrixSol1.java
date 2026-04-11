class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m=matrix.length, n=matrix[0].length;
        boolean[][] vis = new boolean[m][n];
        int[][] dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir=0, r=0, c=0;
        List<Integer> res = new ArrayList<>();
        for (int i=0; i<m*n; i++) { res.add(matrix[r][c]); vis[r][c]=true;
            int nr=r+dirs[dir][0], nc=c+dirs[dir][1];
            if (nr<0||nr>=m||nc<0||nc>=n||vis[nr][nc]) { dir=(dir+1)%4; nr=r+dirs[dir][0]; nc=c+dirs[dir][1]; }
            r=nr; c=nc; }
        return res;
    }
}