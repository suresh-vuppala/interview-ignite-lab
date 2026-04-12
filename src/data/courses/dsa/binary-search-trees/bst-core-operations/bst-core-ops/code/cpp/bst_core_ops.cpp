// ============================================================
// BST Core Operations
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* search(TreeNode* root, int val) {
        if (!root || root->val == val) return root;
        return val < root->val ? search(root->left, val) : search(root->right, val);
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insert(root->left, val);
        else if (val > root->val) root->right = insert(root->right, val);
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left;
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }

    int findMin(TreeNode* root) { while (root->left) root = root->left; return root->val; }
    int findMax(TreeNode* root) { while (root->right) root = root->right; return root->val; }
};
