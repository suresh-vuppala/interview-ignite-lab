public class GcdLcm {
    int gcd(int a, int b) { return b==0?a:gcd(b,a%b); }
    long lcm(int a, int b) { return (long)a*b/gcd(a,b); }
    boolean coprime(int a, int b) { return gcd(a,b)==1; }
    int[] extGcd(int a, int b) { if(b==0) return new int[]{a,1,0}; int[] r=extGcd(b,a%b); return new int[]{r[0],r[2],r[1]-a/b*r[2]}; }
    public static void main(String[] a) { GcdLcm g=new GcdLcm(); System.out.println("GCD(12,18): "+g.gcd(12,18)); System.out.println("LCM(12,18): "+g.lcm(12,18)); }
}