// ============================================================
// Mirror Binary Tree (= Invert Tree)
// ============================================================
#include <algorithm>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* mirror(TreeNode* root) {
        if (!root) return nullptr;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
        return root;
    }
};
