// ============================================================
// Binary Tree Core Operations (BST)
// ============================================================

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BSTOperations {
public:
    // INSERT: O(H) — create node at correct position
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insert(root->left, val);
        else if (val > root->val) root->right = insert(root->right, val);
        return root; // Duplicate: do nothing
    }

    // SEARCH: O(H) — follow BST property
    bool search(TreeNode* root, int val) {
        if (!root) return false;
        if (val == root->val) return true;
        if (val < root->val) return search(root->left, val);
        return search(root->right, val);
    }

    // DELETE: O(H) — handle 3 cases
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (val < root->val) root->left = deleteNode(root->left, val);
        else if (val > root->val) root->right = deleteNode(root->right, val);
        else {
            // Case 1 & 2: Leaf or one child
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            // Case 3: Two children — replace with inorder successor
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left; // Find smallest in right
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};
