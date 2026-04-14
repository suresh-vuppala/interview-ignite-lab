struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <vector>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Insert one by one — O(N²) worst case (sorted input)
// ============================================================
class Solution1 {
    TreeNode* insert(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        if(val<root->val)root->left=insert(root->left,val);else root->right=insert(root->right,val);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root=nullptr; for(int v:preorder)root=insert(root,v); return root;
    }
};

// ============================================================
// Solution 2: Bound-based recursion — O(N) Time
// ============================================================
class Solution2 {
    int idx = 0;
    TreeNode* build(vector<int>& pre, int bound) {
        if (idx >= (int)pre.size() || pre[idx] > bound) return nullptr;
        TreeNode* node = new TreeNode(pre[idx++]);
        node->left = build(pre, node->val);
        node->right = build(pre, bound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) { idx=0; return build(preorder, INT_MAX); }
};
