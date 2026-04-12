// ============================================================
// BST from Preorder
// ============================================================
#include <vector>
#include <climits>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    int idx = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx = 0;
        return build(preorder, INT_MAX);
    }
    TreeNode* build(vector<int>& pre, int bound) {
        if (idx >= (int)pre.size() || pre[idx] > bound) return nullptr;
        TreeNode* root = new TreeNode(pre[idx++]);
        root->left = build(pre, root->val);  // Left: bounded by root value
        root->right = build(pre, bound);      // Right: bounded by parent's bound
        return root;
    }
};
