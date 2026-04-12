// ============================================================
// BST from Postorder
// ============================================================
#include <vector>
#include <climits>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    int idx;
public:
    TreeNode* bstFromPostorder(vector<int>& postorder) {
        idx = postorder.size() - 1;
        return build(postorder, INT_MIN);
    }
    TreeNode* build(vector<int>& post, int bound) {
        if (idx < 0 || post[idx] < bound) return nullptr;
        TreeNode* root = new TreeNode(post[idx--]);
        root->right = build(post, root->val); // Right first (reverse order)
        root->left = build(post, bound);
        return root;
    }
};
