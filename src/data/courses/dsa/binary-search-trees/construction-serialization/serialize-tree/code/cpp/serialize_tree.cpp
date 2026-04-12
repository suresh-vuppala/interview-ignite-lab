// ============================================================
// Serialize Binary Tree
// ============================================================
#include <string>
#include <queue>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null";
        string result;
        queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left); q.push(node->right);
            } else {
                result += "null,";
            }
        }
        return result;
    }
};
