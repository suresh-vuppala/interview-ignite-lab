struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Recursive — prune subtrees without 1 — O(N)
// ============================================================
class Solution1 {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        root->left=pruneTree(root->left); root->right=pruneTree(root->right);
        if(!root->left&&!root->right&&root->val==0) return nullptr;
        return root;
    }
};

// ============================================================
// Solution 2: Postorder with contains-one check — O(N)
// ============================================================
class Solution2 {
    bool containsOne(TreeNode* n) {
        if(!n) return false;
        bool l=containsOne(n->left), r=containsOne(n->right);
        if(!l) n->left=nullptr; if(!r) n->right=nullptr;
        return n->val==1||l||r;
    }
public:
    TreeNode* pruneTree(TreeNode* root) { return containsOne(root)?root:nullptr; }
};
