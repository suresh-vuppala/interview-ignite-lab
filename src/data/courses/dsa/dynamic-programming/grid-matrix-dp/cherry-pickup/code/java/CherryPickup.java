class Solution {
    public int cherryPickup(int[][] grid) {
        int n=grid.length; int[][][] dp=new int[n][n][n];
        for(var a:dp) for(var b:a) java.util.Arrays.fill(b,-1);
        dp[0][0][0]=grid[0][0];
        for(int r1=0;r1<n;r1++) for(int c1=0;c1<n;c1++) for(int r2=0;r2<n;r2++){
            int c2=r1+c1-r2; if(c2<0||c2>=n||grid[r1][c1]==-1||grid[r2][c2]==-1) continue;
            int v=grid[r1][c1]; if(r1!=r2) v+=grid[r2][c2]; int b=-1;
            int[][] pr={{r1-1,c1},{r1,c1-1}};
            for(int[] p1:pr) for(int[] p2:new int[][]{{r2-1,c2},{r2,c2-1}})
                if(p1[0]>=0&&p1[1]>=0&&p2[0]>=0&&p2[1]>=0&&dp[p1[0]][p1[1]][p2[0]]>=0) b=Math.max(b,dp[p1[0]][p1[1]][p2[0]]);
            if(b>=0||(r1==0&&c1==0&&r2==0)) dp[r1][c1][r2]=v+Math.max(0,b);}
        return Math.max(0,dp[n-1][n-1][n-1]);
    }
}