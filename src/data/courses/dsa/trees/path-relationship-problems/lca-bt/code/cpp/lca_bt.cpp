// ============================================================
// Lowest Common Ancestor of Binary Tree
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base: null or found p or q
        if (!root || root == p || root == q) return root;

        // Search both subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null → this is the LCA
        if (left && right) return root;

        // Otherwise, LCA is in the non-null side
        return left ? left : right;
    }
};
