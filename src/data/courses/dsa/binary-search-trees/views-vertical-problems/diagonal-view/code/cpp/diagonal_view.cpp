#include <vector>
#include <queue>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
class Solution {
public:
    vector<vector<int>> diagonalView(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> diag;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                while (node) {
                    diag.push_back(node->val);
                    if (node->left) q.push(node->left);
                    node = node->right;
                }
            }
            result.push_back(diag);
        }
        return result;
    }
};
