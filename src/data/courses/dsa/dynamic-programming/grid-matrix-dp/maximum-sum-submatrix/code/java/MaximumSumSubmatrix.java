class Solution {
    public int maxSumSubmatrix(int[][] mat) {
        int m=mat.length,n=mat[0].length,max=Integer.MIN_VALUE;
        for(int l=0;l<n;l++){int[] rs=new int[m];
            for(int r=l;r<n;r++){for(int i=0;i<m;i++) rs[i]+=mat[i][r];
                int c=0,b=Integer.MIN_VALUE; for(int s:rs){c=Math.max(s,c+s);b=Math.max(b,c);} max=Math.max(max,b);}}
        return max;
    }
}