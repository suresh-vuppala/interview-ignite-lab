struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Recursive insert/search/delete — O(H) avg, O(N) worst
// ============================================================
class Solution1 {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }
    bool search(TreeNode* root, int val) {
        if (!root) return false;
        if (val == root->val) return true;
        return val < root->val ? search(root->left, val) : search(root->right, val);
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
};

// ============================================================
// Solution 2: Iterative insert/search — O(H) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    TreeNode* insert(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) return node;
        TreeNode* cur = root;
        while (true) {
            if (val < cur->val) { if (!cur->left) { cur->left = node; break; } cur = cur->left; }
            else { if (!cur->right) { cur->right = node; break; } cur = cur->right; }
        }
        return root;
    }
    bool search(TreeNode* root, int val) {
        while (root) { if (val == root->val) return true; root = val < root->val ? root->left : root->right; }
        return false;
    }
};
