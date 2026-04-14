struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
// ============================================================
// Solution 1: Recursion — O(2^N) Time (overlapping subproblems)
// ============================================================
#include <algorithm>
using namespace std;
class Solution1 {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        int skip = rob(root->left) + rob(root->right);
        int take = root->val;
        if (root->left) take += rob(root->left->left) + rob(root->left->right);
        if (root->right) take += rob(root->right->left) + rob(root->right->right);
        return max(skip, take);
    }
};

// ============================================================
// Solution 2: DP — Postorder returning (skip, take) pair — O(N) Time
// ============================================================
class Solution2 {
public:
    pair<int,int> dfs(TreeNode* n) {
        if (!n) return {0,0};
        auto [ls,lt] = dfs(n->left);
        auto [rs,rt] = dfs(n->right);
        int skip = max(ls,lt) + max(rs,rt);
        int take = n->val + ls + rs;
        return {skip, take};
    }
    int rob(TreeNode* root) { auto [s,t] = dfs(root); return max(s,t); }
};
