struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS with depth tracking — O(N) Time, O(N) Space
// ============================================================
class Solution1 {
    void dfs(TreeNode* n, int depth, vector<vector<int>>& res) {
        if (!n) return;
        if (depth >= (int)res.size()) res.push_back({});
        res[depth].push_back(n->val);
        dfs(n->left, depth+1, res); dfs(n->right, depth+1, res);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) { vector<vector<int>> res; dfs(root,0,res); return res; }
};

// ============================================================
// Solution 2: BFS with queue — O(N) Time, O(W) Space
// ============================================================
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res; queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int sz=q.size(); vector<int> level;
            while (sz--) { auto n=q.front();q.pop(); level.push_back(n->val); if(n->left)q.push(n->left); if(n->right)q.push(n->right); }
            res.push_back(level);
        }
        return res;
    }
};
