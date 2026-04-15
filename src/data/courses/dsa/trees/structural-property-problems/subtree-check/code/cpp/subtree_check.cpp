struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Serialize both trees, check substring — O(M+N)
// ============================================================
#include <string>
class Solution1 {
    string serialize(TreeNode* n) { if(!n) return "#"; return to_string(n->val)+","+serialize(n->left)+","+serialize(n->right); }
public:
    bool isSubtree(TreeNode* root, TreeNode* sub) { return serialize(root).find(serialize(sub))!=string::npos; }
};

// ============================================================
// Solution 2: Recursive comparison at each node — O(M*N)
// ============================================================
class Solution2 {
    bool same(TreeNode* a, TreeNode* b) { if(!a&&!b)return true; if(!a||!b)return false; return a->val==b->val&&same(a->left,b->left)&&same(a->right,b->right); }
public:
    bool isSubtree(TreeNode* root, TreeNode* sub) { if(!root)return false; return same(root,sub)||isSubtree(root->left,sub)||isSubtree(root->right,sub); }
};
