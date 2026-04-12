// ============================================================
// Kruskal's MST
// ============================================================
import java.util.*;
class Solution {
    int[] pa, rk;
    int find(int x){return pa[x]==x?x:(pa[x]=find(pa[x]));}
    boolean unite(int x,int y){int a=find(x),b=find(y);if(a==b)return false;if(rk[a]<rk[b]){int t=a;a=b;b=t;}pa[b]=a;if(rk[a]==rk[b])rk[a]++;return true;}
    public int kruskalMST(int n, int[][] edges) {
        pa=new int[n]; rk=new int[n]; for(int i=0;i<n;i++) pa[i]=i;
        Arrays.sort(edges, (a,b)->a[2]-b[2]);
        int total = 0, cnt = 0;
        for (int[] e : edges)
            if (unite(e[0],e[1])) { total+=e[2]; if(++cnt==n-1) break; }
        return total;
    }
}
