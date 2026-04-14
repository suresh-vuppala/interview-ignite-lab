struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Insert one by one — O(N²) worst case
// ============================================================
class Solution1 {
    TreeNode* insert(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        if(val<root->val)root->left=insert(root->left,val);else root->right=insert(root->right,val);
        return root;
    }
public:
    TreeNode* bstFromPostorder(vector<int>& postorder) {
        TreeNode*root=nullptr; for(int v:postorder)root=insert(root,v); return root;
    }
};

// ============================================================
// Solution 2: Reverse traversal with bound — O(N) Time
// ============================================================
class Solution2 {
    int idx;
    TreeNode* build(vector<int>& post, int bound) {
        if (idx < 0 || post[idx] < bound) return nullptr;
        TreeNode* node = new TreeNode(post[idx--]);
        node->right = build(post, node->val);
        node->left = build(post, bound);
        return node;
    }
public:
    TreeNode* bstFromPostorder(vector<int>& postorder) { idx=postorder.size()-1; return build(postorder, INT_MIN); }
};
