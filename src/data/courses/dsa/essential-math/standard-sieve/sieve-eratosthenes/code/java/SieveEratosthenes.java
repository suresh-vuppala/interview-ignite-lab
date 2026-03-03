import java.util.*;
public class SieveEratosthenes {
    boolean[] sieve(int n) { boolean[] p=new boolean[n+1]; Arrays.fill(p,true); p[0]=p[1]=false; for(int i=2;i*i<=n;i++) if(p[i]) for(int j=i*i;j<=n;j+=i) p[j]=false; return p; }
    int countPrimes(int n) { boolean[] p=sieve(n); int c=0; for(boolean b:p) if(b) c++; return c; }
    int[] spfArray(int n) { int[] spf=new int[n+1]; for(int i=0;i<=n;i++) spf[i]=i; for(int i=2;i*i<=n;i++) if(spf[i]==i) for(int j=i*i;j<=n;j+=i) if(spf[j]==j) spf[j]=i; return spf; }
    public static void main(String[] a) { SieveEratosthenes s=new SieveEratosthenes(); System.out.println("Primes up to 30: "+s.countPrimes(30)); }
}