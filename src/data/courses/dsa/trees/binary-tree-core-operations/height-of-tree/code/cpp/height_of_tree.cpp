struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Recursive — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
public:
    int height(TreeNode* root) {
        if (!root) return -1; // or 0 depending on definition
        return 1 + max(height(root->left), height(root->right));
    }
};

// ============================================================
// Solution 2: Iterative BFS level count — O(N) Time, O(W) Space
// ============================================================
class Solution2 {
public:
    int height(TreeNode* root) {
        if (!root) return -1;
        int h = -1;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            h++; int sz = q.size();
            while (sz--) { auto n=q.front();q.pop(); if(n->left)q.push(n->left); if(n->right)q.push(n->right); }
        }
        return h;
    }
};
