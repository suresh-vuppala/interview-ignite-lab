// ============================================================
// Construct BT from Inorder + Postorder
// ============================================================
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    unordered_map<int, int> inMap;
    int postIdx;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        postIdx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& post, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = inMap[root->val];
        root->right = build(post, inIdx + 1, inRight); // Right first!
        root->left = build(post, inLeft, inIdx - 1);
        return root;
    }
};
