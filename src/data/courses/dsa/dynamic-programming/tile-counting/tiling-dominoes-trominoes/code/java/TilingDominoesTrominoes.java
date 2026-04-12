class Solution {
    public int numTilings(int n) {
        if (n<=2) return n; long MOD=1_000_000_007;
        long a=1,b=2,c=5;
        for (int i=4;i<=n;i++){long d=(2*c+a)%MOD;a=b;b=c;c=d;}
        return (int)(n==3?5:c);
    }
}