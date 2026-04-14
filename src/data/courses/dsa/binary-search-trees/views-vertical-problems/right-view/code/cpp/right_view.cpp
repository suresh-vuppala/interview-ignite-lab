struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS — last node at each level — O(N)
// ============================================================
class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res; queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            int sz=q.size();
            while(sz--) { auto n=q.front();q.pop(); if(sz==0)res.push_back(n->val); if(n->left)q.push(n->left);if(n->right)q.push(n->right); }
        }
        return res;
    }
};

// ============================================================
// Solution 2: DFS — visit right first, add first at new depth — O(N)
// ============================================================
class Solution2 {
    void dfs(TreeNode* n, int depth, int& maxDepth, vector<int>& res) {
        if(!n) return;
        if(depth > maxDepth) { res.push_back(n->val); maxDepth = depth; }
        dfs(n->right, depth+1, maxDepth, res);  // Right first!
        dfs(n->left, depth+1, maxDepth, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) { vector<int> res; int md=-1; dfs(root,0,md,res); return res; }
};
