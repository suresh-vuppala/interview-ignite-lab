// ============================================================
// Cousins in Binary Tree
// ============================================================
#include <queue>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        queue<pair<TreeNode*, TreeNode*>> q; // (node, parent)
        q.push({root, nullptr});
        while (!q.empty()) {
            int size = q.size();
            TreeNode *xParent = nullptr, *yParent = nullptr;
            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front(); q.pop();
                if (node->val == x) xParent = parent;
                if (node->val == y) yParent = parent;
                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }
            // Both found at this level with different parents = cousins
            if (xParent && yParent) return xParent != yParent;
            if (xParent || yParent) return false; // Different depths
        }
        return false;
    }
};
