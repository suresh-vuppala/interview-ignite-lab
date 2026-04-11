// ============================================================
// Tree Type Checks: Full, Complete, Perfect
// ============================================================
#include <queue>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    // FULL: Every node has 0 or 2 children
    bool isFullTree(TreeNode* root) {
        if (!root) return true;
        if ((!root->left) != (!root->right)) return false; // One child only
        return isFullTree(root->left) && isFullTree(root->right);
    }

    // COMPLETE: BFS — flag after seeing non-full node
    bool isComplete(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool seenNonFull = false;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                if (seenNonFull) return false;
                q.push(node->left);
            } else seenNonFull = true;
            if (node->right) {
                if (seenNonFull) return false;
                q.push(node->right);
            } else seenNonFull = true;
        }
        return true;
    }

    // PERFECT: Left depth == Right depth
    bool isPerfect(TreeNode* root) {
        int lh = 0, rh = 0;
        TreeNode *l = root, *r = root;
        while (l) { lh++; l = l->left; }
        while (r) { rh++; r = r->right; }
        return lh == rh;
    }
};
