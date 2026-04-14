#include <vector>
using namespace std;
// ============================================================
// Solution 1: DFS — O(N²)
// ============================================================
class Solution1 {
    void dfs(vector<vector<int>>&M,int i,vector<bool>&vis){vis[i]=true;for(int j=0;j<(int)M.size();j++)if(M[i][j]&&!vis[j])dfs(M,j,vis);}
public:
    int findCircleNum(vector<vector<int>>&M){int n=M.size(),c=0;vector<bool>vis(n,false);for(int i=0;i<n;i++)if(!vis[i]){dfs(M,i,vis);c++;}return c;}
};

// ============================================================
// Solution 2: Union-Find — O(N² * α(N))
// ============================================================
class Solution2 {
    vector<int>par,rnk;
    int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
    void unite(int a,int b){int pa=find(a),pb=find(b);if(pa==pb)return;if(rnk[pa]<rnk[pb])swap(pa,pb);par[pb]=pa;if(rnk[pa]==rnk[pb])rnk[pa]++;}
public:
    int findCircleNum(vector<vector<int>>&M){
        int n=M.size();par.resize(n);rnk.resize(n,0);for(int i=0;i<n;i++)par[i]=i;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(M[i][j])unite(i,j);
        int c=0;for(int i=0;i<n;i++)if(find(i)==i)c++;return c;
    }
};
