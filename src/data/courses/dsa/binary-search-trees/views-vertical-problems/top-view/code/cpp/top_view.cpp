struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
#include <map>
using namespace std;
// ============================================================
// Solution 1: BFS with horizontal distance — map keeps first per HD — O(N log N)
// ============================================================
class Solution1 {
public:
    vector<int> topView(TreeNode* root) {
        if(!root) return {};
        map<int,int> hdMap; // HD → first node value
        queue<pair<TreeNode*,int>> q; q.push({root,0});
        while(!q.empty()) {
            auto [n,hd]=q.front();q.pop();
            if(!hdMap.count(hd)) hdMap[hd]=n->val; // First at this HD = top view
            if(n->left)q.push({n->left,hd-1});if(n->right)q.push({n->right,hd+1});
        }
        vector<int> res; for(auto&[k,v]:hdMap)res.push_back(v); return res;
    }
};

// ============================================================
// Solution 2: DFS with level tracking — keep shallowest per HD — O(N)
// ============================================================
class Solution2 {
    map<int,pair<int,int>> hdMap; // HD → {level, value}
    void dfs(TreeNode* n, int hd, int level) {
        if(!n) return;
        if(!hdMap.count(hd) || level < hdMap[hd].first) hdMap[hd] = {level, n->val};
        dfs(n->left, hd-1, level+1); dfs(n->right, hd+1, level+1);
    }
public:
    vector<int> topView(TreeNode* root) {
        hdMap.clear(); dfs(root,0,0);
        vector<int> res; for(auto&[k,p]:hdMap) res.push_back(p.second); return res;
    }
};
