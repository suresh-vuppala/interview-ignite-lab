struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Recursive mirror check — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
    bool isMirror(TreeNode* a, TreeNode* b) {
        if(!a&&!b) return true; if(!a||!b) return false;
        return a->val==b->val && isMirror(a->left,b->right) && isMirror(a->right,b->left);
    }
public:
    bool isSymmetric(TreeNode* root) { return !root || isMirror(root->left,root->right); }
};

// ============================================================
// Solution 2: Iterative BFS with queue — O(N) Time, O(W) Space
// ============================================================
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q; q.push(root->left); q.push(root->right);
        while(!q.empty()) {
            auto a=q.front();q.pop(); auto b=q.front();q.pop();
            if(!a&&!b) continue; if(!a||!b||a->val!=b->val) return false;
            q.push(a->left);q.push(b->right);q.push(a->right);q.push(b->left);
        }
        return true;
    }
};
