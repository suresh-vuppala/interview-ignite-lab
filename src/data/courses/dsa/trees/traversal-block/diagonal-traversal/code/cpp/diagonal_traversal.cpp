// ============================================================
// Diagonal Traversal
// ============================================================
#include <vector>
#include <queue>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<vector<int>> diagonalTraversal(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> diagonal;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                // Follow right chain — same diagonal
                while (node) {
                    diagonal.push_back(node->val);
                    if (node->left) q.push(node->left); // Left = next diagonal
                    node = node->right; // Right = same diagonal
                }
            }
            result.push_back(diagonal);
        }
        return result;
    }
};
