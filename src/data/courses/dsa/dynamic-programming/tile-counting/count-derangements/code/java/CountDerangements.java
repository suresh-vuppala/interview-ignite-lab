class Solution {
    public long countDerangements(int n) {
        if (n==1) return 0; if (n==2) return 1;
        long a=0, b=1, MOD=1_000_000_007;
        for (int i=3;i<=n;i++){long c=(i-1)*((a+b)%MOD)%MOD;a=b;b=c;} return b;
    }
}