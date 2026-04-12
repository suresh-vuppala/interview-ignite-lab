// ============================================================
// Construct BT from Inorder + Preorder
// ============================================================
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    unordered_map<int, int> inMap;
    int preIdx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        preIdx = 0;
        return build(preorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& pre, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        int rootVal = pre[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int inIdx = inMap[rootVal]; // Root position in inorder
        root->left = build(pre, inLeft, inIdx - 1);
        root->right = build(pre, inIdx + 1, inRight);
        return root;
    }
};
