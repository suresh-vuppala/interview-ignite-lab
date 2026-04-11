// ============================================================
// Binary Tree Zigzag Level Order Traversal
// ============================================================

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Reverse for right-to-left levels
            if (!leftToRight) reverse(level.begin(), level.end());
            result.push_back(level);
            leftToRight = !leftToRight; // Toggle direction
        }

        return result;
    }
};
