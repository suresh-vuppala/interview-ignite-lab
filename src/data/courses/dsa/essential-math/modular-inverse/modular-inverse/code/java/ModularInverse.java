public class ModularInverse {
    long extGcd(long a, long b, long[] xy) { if(b==0) { xy[0]=1; xy[1]=0; return a; } long g=extGcd(b,a%b,xy); long x1=xy[0],y1=xy[1]; xy[0]=y1; xy[1]=x1-a/b*y1; return g; }
    long modInvEuclid(long a, long m) { long[] xy=new long[2]; long g=extGcd(a,m,xy); return g==1?(xy[0]%m+m)%m:-1; }
    long modInvFermat(long a, long m) { return pow(a,m-2,m); }
    long pow(long a, long b, long m) { long r=1; a%=m; while(b>0) { if((b&1)==1) r=(r*a)%m; a=(a*a)%m; b>>=1; } return r; }
    public static void main(String[] a) { ModularInverse m=new ModularInverse(); long MOD=1000000007; System.out.println("Inverse of 3 mod "+MOD+": "+m.modInvFermat(3,MOD)); }
}