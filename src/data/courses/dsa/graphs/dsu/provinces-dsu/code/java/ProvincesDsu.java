// ============================================================
// Provinces DSU
// ============================================================
class Solution {
    int[] p, r;
    int find(int x){return p[x]==x?x:(p[x]=find(p[x]));}
    void unite(int x,int y){int a=find(x),b=find(y);if(a==b)return;if(r[a]<r[b]){int t=a;a=b;b=t;}p[b]=a;if(r[a]==r[b])r[a]++;}
    public int findCircleNum(int[][] M) {
        int n=M.length; p=new int[n]; r=new int[n]; for(int i=0;i<n;i++) p[i]=i;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(M[i][j]==1) unite(i,j);
        int c=0; for(int i=0;i<n;i++) if(find(i)==i) c++; return c;
    }
}
