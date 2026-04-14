#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS — O(N²) Time (adjacency matrix)
// ============================================================
class Solution1 {
    void dfs(vector<vector<int>>& M, int i, vector<bool>& vis) {
        vis[i] = true;
        for (int j = 0; j < (int)M.size(); j++)
            if (M[i][j] == 1 && !vis[j]) dfs(M, j, vis);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
            if (!vis[i]) { dfs(isConnected, i, vis); count++; }
        return count;
    }
};

// ============================================================
// Solution 2: Union-Find (DSU) — O(N² * α(N)) ≈ O(N²) Time
// ============================================================
class Solution2 {
    vector<int> parent, rank_;
    int find(int x) { return parent[x]==x ? x : parent[x]=find(parent[x]); }
    void unite(int x, int y) {
        int px=find(x), py=find(y);
        if(px==py) return;
        if(rank_[px]<rank_[py]) swap(px,py);
        parent[py]=px;
        if(rank_[px]==rank_[py]) rank_[px]++;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n); rank_.resize(n, 0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
            if(isConnected[i][j]) unite(i,j);
        int count=0;
        for(int i=0;i<n;i++) if(find(i)==i) count++;
        return count;
    }
};
