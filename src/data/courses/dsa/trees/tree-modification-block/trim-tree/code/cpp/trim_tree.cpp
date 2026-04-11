// ============================================================
// Trim a Binary Search Tree
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // Too small — skip this node and left subtree
        if (root->val < low) return trimBST(root->right, low, high);

        // Too large — skip this node and right subtree
        if (root->val > high) return trimBST(root->left, low, high);

        // In range — trim both children
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
