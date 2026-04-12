// ============================================================
// Left View of Binary Tree
// ============================================================
#include <vector>
#include <queue>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<int> leftView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                if (i == 0) result.push_back(node->val); // First at this level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};
