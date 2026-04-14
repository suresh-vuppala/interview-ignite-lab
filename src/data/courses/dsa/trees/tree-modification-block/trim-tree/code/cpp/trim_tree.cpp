struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Recursive — prune out-of-range nodes — O(N)
// ============================================================
class Solution1 {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;
        if(root->val<low) return trimBST(root->right,low,high);
        if(root->val>high) return trimBST(root->left,low,high);
        root->left=trimBST(root->left,low,high);
        root->right=trimBST(root->right,low,high);
        return root;
    }
};

// ============================================================
// Solution 2: Iterative — O(N)
// ============================================================
class Solution2 {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(root&&(root->val<low||root->val>high)) root=root->val<low?root->right:root->left;
        TreeNode* cur=root;
        while(cur) { while(cur->left&&cur->left->val<low) cur->left=cur->left->right; cur=cur->left; }
        cur=root;
        while(cur) { while(cur->right&&cur->right->val>high) cur->right=cur->right->left; cur=cur->right; }
        return root;
    }
};
