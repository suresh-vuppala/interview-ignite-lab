struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Height at each node, compute diameter — O(N²)
// ============================================================
class Solution1 {
    int height(TreeNode* n) { return n ? 1+max(height(n->left),height(n->right)) : 0; }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int through = height(root->left) + height(root->right);
        return max({through, diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }
};

// ============================================================
// Solution 2: Single DFS — track diameter while computing height — O(N)
// ============================================================
class Solution2 {
    int dia = 0;
    int height(TreeNode* n) { if(!n) return 0; int l=height(n->left),r=height(n->right); dia=max(dia,l+r); return 1+max(l,r); }
public:
    int diameterOfBinaryTree(TreeNode* root) { dia=0; height(root); return dia; }
};
