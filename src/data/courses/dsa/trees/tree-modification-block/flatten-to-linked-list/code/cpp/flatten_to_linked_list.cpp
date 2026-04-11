// ============================================================
// Flatten Binary Tree to Linked List
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution1 {
    TreeNode* prev = nullptr;
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);  // Process right first
        flatten(root->left);   // Then left
        // Now link: root.right = prev, root.left = null
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

// O(1) space Morris-style
class Solution2 {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // Find rightmost of left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right) rightmost = rightmost->right;
                // Connect rightmost to curr's right child
                rightmost->right = curr->right;
                // Move left subtree to right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
