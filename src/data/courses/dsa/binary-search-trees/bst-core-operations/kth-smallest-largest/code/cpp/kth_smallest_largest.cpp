// ============================================================
// Kth Smallest/Largest in BST
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    int count, result;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k; result = -1;
        inorder(root);
        return result;
    }
    void inorder(TreeNode* node) {
        if (!node || count <= 0) return;
        inorder(node->left);
        if (--count == 0) { result = node->val; return; }
        inorder(node->right);
    }

    int kthLargest(TreeNode* root, int k) {
        count = k; result = -1;
        reverseInorder(root);
        return result;
    }
    void reverseInorder(TreeNode* node) {
        if (!node || count <= 0) return;
        reverseInorder(node->right); // Right first
        if (--count == 0) { result = node->val; return; }
        reverseInorder(node->left);
    }
};
