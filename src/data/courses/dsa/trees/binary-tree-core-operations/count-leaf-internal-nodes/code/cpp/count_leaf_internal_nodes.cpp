// ============================================================
// Count Leaf and Internal Nodes
// ============================================================

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int countLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1; // Leaf
        return countLeaves(root->left) + countLeaves(root->right);
    }

    int countInternal(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0; // Leaf — not internal
        return 1 + countInternal(root->left) + countInternal(root->right);
    }
};
