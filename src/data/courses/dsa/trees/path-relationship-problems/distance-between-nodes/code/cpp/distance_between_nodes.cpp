// ============================================================
// Distance Between Two Nodes
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* lca = findLCA(root, p, q);
        return depth(lca, p, 0) + depth(lca, q, 0);
    }
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) return root;
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
    int depth(TreeNode* root, int target, int d) {
        if (!root) return -1;
        if (root->val == target) return d;
        int left = depth(root->left, target, d + 1);
        if (left != -1) return left;
        return depth(root->right, target, d + 1);
    }
};
