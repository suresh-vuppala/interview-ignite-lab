struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Recursive creation + traversal — O(N) each
// ============================================================
class Solution1 {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            TreeNode* n = q.front(); q.pop();
            if (!n->left) { n->left = new TreeNode(val); return root; }
            else q.push(n->left);
            if (!n->right) { n->right = new TreeNode(val); return root; }
            else q.push(n->right);
        }
        return root;
    }
    int size(TreeNode* root) { return root ? 1 + size(root->left) + size(root->right) : 0; }
};

// ============================================================
// Solution 2: Level-order insert + iterative size — O(N)
// ============================================================
class Solution2 {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            TreeNode* n = q.front(); q.pop();
            if (!n->left) { n->left = new TreeNode(val); break; }
            q.push(n->left);
            if (!n->right) { n->right = new TreeNode(val); break; }
            q.push(n->right);
        }
        return root;
    }
    int size(TreeNode* root) {
        if (!root) return 0;
        int c = 0; queue<TreeNode*> q; q.push(root);
        while (!q.empty()) { c++; auto n=q.front(); q.pop(); if(n->left)q.push(n->left); if(n->right)q.push(n->right); }
        return c;
    }
};
