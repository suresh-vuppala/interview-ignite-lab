import java.util.*;
public class GrundyNumbers {
    int mex(Set<Integer> s) { int m=0; while(s.contains(m)) m++; return m; }
    int grundy(int n, int[] moves) { if(n==0) return 0; Set<Integer> s=new HashSet<>(); for(int m:moves) if(n>=m) s.add(grundy(n-m,moves)); return mex(s); }
    public static void main(String[] a) { GrundyNumbers g=new GrundyNumbers(); int[] moves={1,2,3}; System.out.println("Grundy(5): "+g.grundy(5,moves)); }
}