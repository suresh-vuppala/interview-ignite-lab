// ============================================================
// Binary Tree Pruning
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        // Prune if no 1 in this subtree
        if (!root->left && !root->right && root->val == 0)
            return nullptr;
        return root;
    }
};
