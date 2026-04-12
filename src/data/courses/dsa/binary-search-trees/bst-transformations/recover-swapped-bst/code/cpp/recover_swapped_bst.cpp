// ============================================================
// Recover BST (Two Swapped Nodes)
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
public:
    void recoverTree(TreeNode* root) {
        first = second = prev = nullptr;
        inorder(root);
        // Swap values of the two misplaced nodes
        int temp = first->val; first->val = second->val; second->val = temp;
    }
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev && prev->val > node->val) {
            if (!first) first = prev; // First violation: prev is too large
            second = node;             // Second violation: curr is too small
        }
        prev = node;
        inorder(node->right);
    }
};
