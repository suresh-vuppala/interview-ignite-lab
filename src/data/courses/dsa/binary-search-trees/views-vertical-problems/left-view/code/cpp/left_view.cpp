struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS — first node at each level — O(N)
// ============================================================
class Solution1 {
public:
    vector<int> leftView(TreeNode* root) {
        if(!root) return {};
        vector<int> res; queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            int sz=q.size(); bool first=true;
            while(sz--) { auto n=q.front();q.pop(); if(first){res.push_back(n->val);first=false;} if(n->left)q.push(n->left);if(n->right)q.push(n->right); }
        }
        return res;
    }
};

// ============================================================
// Solution 2: DFS — track max depth, add first node at new depth — O(N)
// ============================================================
class Solution2 {
    void dfs(TreeNode* n, int depth, int& maxDepth, vector<int>& res) {
        if(!n) return;
        if(depth > maxDepth) { res.push_back(n->val); maxDepth = depth; }
        dfs(n->left, depth+1, maxDepth, res);
        dfs(n->right, depth+1, maxDepth, res);
    }
public:
    vector<int> leftView(TreeNode* root) { vector<int> res; int md=-1; dfs(root,0,md,res); return res; }
};
