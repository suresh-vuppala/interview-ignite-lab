// ============================================================
// BST to Sorted Doubly Linked List
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
        if (!prev) head = node;
        else { prev->right = node; node->left = prev; }
        prev = node;
        inorder(node->right);
    }
};
