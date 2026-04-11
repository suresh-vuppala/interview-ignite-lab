class Solution {
    int[] parent, rank;
    int find(int x) { return parent[x]==x?x:(parent[x]=find(parent[x])); }
    boolean union(int a, int b) { a=find(a);b=find(b); if(a==b)return false; if(rank[a]<rank[b]){int t=a;a=b;b=t;} parent[b]=a; if(rank[a]==rank[b])rank[a]++; return true; }
    public int kruskalMST(int V, int[][] edges) {
        parent=new int[V]; rank=new int[V]; for(int i=0;i<V;i++)parent[i]=i;
        Arrays.sort(edges, (a,b)->a[2]-b[2]);
        int total=0, count=0;
        for(int[] e:edges) if(union(e[0],e[1])) { total+=e[2]; if(++count==V-1)break; }
        return total;
    }
}