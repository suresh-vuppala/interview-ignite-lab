struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
using namespace std;
// ============================================================
// Solution 1: Recursive count — O(N) Time, O(H) Space
// ============================================================
class Solution1 {
public:
    int countLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }
    int countInternal(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return 0;
        return 1 + countInternal(root->left) + countInternal(root->right);
    }
};

// ============================================================
// Solution 2: Iterative BFS count — O(N) Time, O(W) Space
// ============================================================
#include <queue>
class Solution2 {
public:
    pair<int,int> count(TreeNode* root) {
        if (!root) return {0,0};
        int leaves=0, internal=0;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            if (!n->left && !n->right) leaves++;
            else internal++;
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        return {leaves, internal};
    }
};
