struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
#include <map>
using namespace std;
// ============================================================
// Solution 1: DFS with diagonal index map — O(N log N)
// ============================================================
class Solution1 {
    void dfs(TreeNode* n, int d, map<int,vector<int>>& m) {
        if(!n)return; m[d].push_back(n->val); dfs(n->left,d+1,m); dfs(n->right,d,m);
    }
public:
    vector<vector<int>> diagonalTraversal(TreeNode* root) {
        map<int,vector<int>> m; dfs(root,0,m);
        vector<vector<int>> res; for(auto&[k,v]:m) res.push_back(v); return res;
    }
};

// ============================================================
// Solution 2: BFS — queue processes diagonals — O(N)
// ============================================================
class Solution2 {
public:
    vector<vector<int>> diagonalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res; queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            int sz=q.size(); vector<int> diag;
            while(sz--) {
                TreeNode* n=q.front();q.pop();
                while(n) { diag.push_back(n->val); if(n->left)q.push(n->left); n=n->right; }
            }
            res.push_back(diag);
        }
        return res;
    }
};
