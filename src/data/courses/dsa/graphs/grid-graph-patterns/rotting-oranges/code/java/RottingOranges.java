// ============================================================
// Rotting Oranges
// ============================================================
import java.util.*;
class Solution {
    public int orangesRotting(int[][] grid) {
        int m=grid.length, n=grid[0].length, fresh=0, min=0;
        Queue<int[]> q = new LinkedList<>();
        for (int i=0;i<m;i++) for (int j=0;j<n;j++) {
            if (grid[i][j]==2) q.add(new int[]{i,j});
            if (grid[i][j]==1) fresh++;
        }
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.isEmpty() && fresh>0) {
            int size=q.size(); min++;
            for (int k=0;k<size;k++) {
                int[] c = q.poll();
                for (int[] d : dirs) {
                    int nr=c[0]+d[0], nc=c[1]+d[1];
                    if (nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1) {
                        grid[nr][nc]=2; fresh--; q.add(new int[]{nr,nc});
                    }
                }
            }
        }
        return fresh==0 ? min : -1;
    }
}
