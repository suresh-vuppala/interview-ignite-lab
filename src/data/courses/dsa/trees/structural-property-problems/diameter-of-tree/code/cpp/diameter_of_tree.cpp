// ============================================================
// Diameter of Binary Tree
// ============================================================

#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution1 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int through = height(root->left) + height(root->right);
        return max({through, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }
    int height(TreeNode* n) { return n ? 1+max(height(n->left),height(n->right)) : 0; }
};

class Solution2 {
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        height(root);
        return diameter;
    }
    int height(TreeNode* node) {
        if (!node) return 0;
        int leftH = height(node->left);
        int rightH = height(node->right);
        // Update diameter: longest path through this node
        diameter = max(diameter, leftH + rightH);
        return 1 + max(leftH, rightH);
    }
};
