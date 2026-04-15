struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
#include <map>
using namespace std;
// ============================================================
// Solution 1: DFS + map of HD → values (may have wrong order) — O(N log N)
// ============================================================
class Solution1 {
    void dfs(TreeNode* n, int hd, int level, map<int,vector<pair<int,int>>>& m) {
        if(!n) return;
        m[hd].push_back({level, n->val});
        dfs(n->left,hd-1,level+1,m); dfs(n->right,hd+1,level+1,m);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int,vector<pair<int,int>>> m; dfs(root,0,0,m);
        vector<vector<int>> res;
        for(auto&[hd,pairs]:m) { sort(pairs.begin(),pairs.end()); vector<int> col; for(auto&[l,v]:pairs)col.push_back(v); res.push_back(col); }
        return res;
    }
};

// ============================================================
// Solution 2: BFS + map — level order guarantees correct within-column order — O(N log N)
// ============================================================
class Solution2 {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q; q.push({root,0});
        while(!q.empty()) { auto[n,hd]=q.front();q.pop(); m[hd].push_back(n->val); if(n->left)q.push({n->left,hd-1});if(n->right)q.push({n->right,hd+1}); }
        vector<vector<int>> res; for(auto&[k,v]:m)res.push_back(v); return res;
    }
};
