public class NcrNpr {
    long nCr(int n, int r) { if(r>n-r) r=n-r; long res=1; for(int i=0;i<r;i++) { res*=(n-i); res/=(i+1); } return res; }
    long nPr(int n, int r) { long res=1; for(int i=0;i<r;i++) res*=(n-i); return res; }
    long[][] pascal(int n) { long[][] c=new long[n+1][n+1]; for(int i=0;i<=n;i++) { c[i][0]=1; for(int j=1;j<=i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j]; } return c; }
    public static void main(String[] a) { NcrNpr nc=new NcrNpr(); System.out.println("C(5,2): "+nc.nCr(5,2)); System.out.println("P(5,2): "+nc.nPr(5,2)); }
}