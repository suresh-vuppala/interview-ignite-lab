// ============================================================
// Balanced Binary Tree
// ============================================================

#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution1 {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lh = height(root->left), rh = height(root->right);
        return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};

class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        int leftH = checkHeight(node->left);
        if (leftH == -1) return -1; // Left unbalanced
        int rightH = checkHeight(node->right);
        if (rightH == -1) return -1; // Right unbalanced
        if (abs(leftH - rightH) > 1) return -1; // Current unbalanced
        return 1 + max(leftH, rightH); // Balanced — return height
    }
};
