public class ModularOperations {
    long MOD=1000000007;
    long add(long a, long b) { return ((a%MOD)+(b%MOD))%MOD; }
    long sub(long a, long b) { return ((a%MOD)-(b%MOD)+MOD)%MOD; }
    long mul(long a, long b) { return ((a%MOD)*(b%MOD))%MOD; }
    long pow(long a, long b) { long r=1; a%=MOD; while(b>0) { if((b&1)==1) r=(r*a)%MOD; a=(a*a)%MOD; b>>=1; } return r; }
    public static void main(String[] args) { ModularOperations m=new ModularOperations(); System.out.println("(10+20)%MOD: "+m.add(10,20)); System.out.println("2^10%MOD: "+m.pow(2,10)); }
}