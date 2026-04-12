// ============================================================
// Detect Cycle Using DSU
// ============================================================
class Solution {
    int[] p, r;
    int find(int x) { return p[x]==x?x:(p[x]=find(p[x])); }
    boolean unite(int x, int y) { int a=find(x),b=find(y); if(a==b) return false;
        if(r[a]<r[b]){int t=a;a=b;b=t;} p[b]=a; if(r[a]==r[b]) r[a]++; return true; }
    public boolean hasCycle(int n, int[][] edges) {
        p=new int[n]; r=new int[n]; for(int i=0;i<n;i++) p[i]=i;
        for (int[] e : edges) if (!unite(e[0], e[1])) return true;
        return false;
    }
}
