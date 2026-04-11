// ============================================================
// Symmetric Tree
// ============================================================

#include <queue>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;           // Both null — symmetric
        if (!l || !r) return false;          // One null — not symmetric
        return l->val == r->val              // Values must match
            && isMirror(l->left, r->right)   // Outer children
            && isMirror(l->right, r->left);  // Inner children
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left); q.push(root->right);
        while (!q.empty()) {
            TreeNode* l = q.front(); q.pop();
            TreeNode* r = q.front(); q.pop();
            if (!l && !r) continue;
            if (!l || !r || l->val != r->val) return false;
            q.push(l->left); q.push(r->right);  // Outer pair
            q.push(l->right); q.push(r->left);  // Inner pair
        }
        return true;
    }
};
