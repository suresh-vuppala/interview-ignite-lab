// ============================================================
// Invert Binary Tree
// ============================================================

#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        // Swap left and right children
        swap(root->left, root->right);

        // Recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
