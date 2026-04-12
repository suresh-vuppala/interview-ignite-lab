// ============================================================
// Validate BST
// ============================================================
#include <climits>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Solution 1: Range Validation
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

// Solution 2: Inorder Check
class Solution2 {
    TreeNode* prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        prev = nullptr;
        return inorder(root);
    }
    bool inorder(TreeNode* node) {
        if (!node) return true;
        if (!inorder(node->left)) return false;
        if (prev && node->val <= prev->val) return false;
        prev = node;
        return inorder(node->right);
    }
};
