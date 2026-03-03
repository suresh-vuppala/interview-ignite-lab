import java.util.*;
public class DivisorsFactors {
    int countDivisors(int n) { int c=0; for(int i=1;i*i<=n;i++) if(n%i==0) c+=i*i==n?1:2; return c; }
    int sumDivisors(int n) { int s=0; for(int i=1;i*i<=n;i++) if(n%i==0) s+=i*i==n?i:i+n/i; return s; }
    List<Integer> allFactors(int n) { List<Integer> f=new ArrayList<>(); for(int i=1;i*i<=n;i++) if(n%i==0) { f.add(i); if(i*i!=n) f.add(n/i); } Collections.sort(f); return f; }
    public static void main(String[] a) { DivisorsFactors d=new DivisorsFactors(); System.out.println("Divisors of 36: "+d.countDivisors(36)); System.out.println("Sum of divisors of 36: "+d.sumDivisors(36)); System.out.println("All factors of 36: "+d.allFactors(36)); }
}