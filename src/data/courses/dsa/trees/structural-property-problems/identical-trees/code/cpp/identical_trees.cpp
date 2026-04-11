// ============================================================
// Same Tree (Identical Trees)
// ============================================================

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;              // Both null — identical
        if (!p || !q) return false;             // One null — not identical
        return p->val == q->val                 // Values must match
            && isSameTree(p->left, q->left)     // Left subtrees match
            && isSameTree(p->right, q->right);  // Right subtrees match
    }
};
