// ============================================================
// Remove Leaf Nodes with Target Value
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;
        // Postorder: process children first
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        // Check if current is now a target leaf
        if (!root->left && !root->right && root->val == target)
            return nullptr; // Delete this node
        return root;
    }
};
