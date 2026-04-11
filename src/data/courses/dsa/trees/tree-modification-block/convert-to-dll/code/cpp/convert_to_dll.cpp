// ============================================================
// Convert Binary Tree to Doubly Linked List (Inorder)
// ============================================================
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;
public:
    TreeNode* treeToDoublyList(TreeNode* root) {
        if (!root) return nullptr;
        prev = nullptr; head = nullptr;
        inorder(root);
        return head;
    }
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (!prev) head = node;       // First node = head
        else { prev->right = node; node->left = prev; } // Link
        prev = node;
        inorder(node->right);
    }
};
