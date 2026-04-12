// ============================================================
// Floor and Ceil in BST
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int floor(TreeNode* root, int key) {
        int result = -1;
        while (root) {
            if (root->val == key) return key;
            if (root->val < key) { result = root->val; root = root->right; }
            else root = root->left;
        }
        return result;
    }

    int ceil(TreeNode* root, int key) {
        int result = -1;
        while (root) {
            if (root->val == key) return key;
            if (root->val > key) { result = root->val; root = root->left; }
            else root = root->right;
        }
        return result;
    }
};
