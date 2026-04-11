// ============================================================
// Maximum Root-to-Leaf Path Sum
// ============================================================
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return INT_MIN;
        if (!root->left && !root->right) return root->val; // Leaf
        if (!root->left) return root->val + maxPathSum(root->right); // Only right
        if (!root->right) return root->val + maxPathSum(root->left); // Only left
        return root->val + max(maxPathSum(root->left), maxPathSum(root->right));
    }
};
