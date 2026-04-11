// ============================================================
// Binary Tree Level Order Traversal
// ============================================================

#include <vector>
#include <queue>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// ============================================================
// Solution: BFS with Queue
// Time: O(N) | Space: O(W)
// ============================================================
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // Nodes at current level
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};
