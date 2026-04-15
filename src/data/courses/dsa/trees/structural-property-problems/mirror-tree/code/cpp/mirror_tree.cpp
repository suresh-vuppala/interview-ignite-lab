struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Recursive swap — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left); invertTree(root->right);
        return root;
    }
};

// ============================================================
// Solution 2: Iterative BFS swap — O(N) Time, O(W) Space
// ============================================================
#include <queue>
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) { auto n=q.front();q.pop(); swap(n->left,n->right); if(n->left)q.push(n->left); if(n->right)q.push(n->right); }
        return root;
    }
};
