// ============================================================
// Construct BT from Level Order
// ============================================================
#include <vector>
#include <queue>
#include <string>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* buildFromLevelOrder(vector<string>& vals) {
        if (vals.empty() || vals[0] == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q; q.push(root);
        int i = 1;
        while (!q.empty() && i < vals.size()) {
            TreeNode* parent = q.front(); q.pop();
            // Left child
            if (i < vals.size() && vals[i] != "null") {
                parent->left = new TreeNode(stoi(vals[i]));
                q.push(parent->left);
            }
            i++;
            // Right child
            if (i < vals.size() && vals[i] != "null") {
                parent->right = new TreeNode(stoi(vals[i]));
                q.push(parent->right);
            }
            i++;
        }
        return root;
    }
};
