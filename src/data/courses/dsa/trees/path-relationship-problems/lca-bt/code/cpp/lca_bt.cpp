struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Find paths from root, compare — O(N) Time, O(N) Space
// ============================================================
#include <vector>
class Solution1 {
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if(!root) return false; path.push_back(root);
        if(root==target) return true;
        if(findPath(root->left,target,path)||findPath(root->right,target,path)) return true;
        path.pop_back(); return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        findPath(root,p,pathP); findPath(root,q,pathQ);
        TreeNode* lca=nullptr;
        for(int i=0;i<min(pathP.size(),pathQ.size());i++) { if(pathP[i]==pathQ[i])lca=pathP[i]; else break; }
        return lca;
    }
};

// ============================================================
// Solution 2: Single recursive pass — O(N) Time, O(H) Space
// ============================================================
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right = lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        return left ? left : right;
    }
};
