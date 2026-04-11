// ============================================================
// Add One Row to Tree
// ============================================================
#include <queue>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        // DFS to depth-1
        dfs(root, val, depth, 1);
        return root;
    }
    void dfs(TreeNode* node, int val, int depth, int current) {
        if (!node) return;
        if (current == depth - 1) {
            // Insert new nodes
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            newLeft->left = node->left;   // Old left becomes new left's left
            newRight->right = node->right; // Old right becomes new right's right
            node->left = newLeft;
            node->right = newRight;
            return;
        }
        dfs(node->left, val, depth, current + 1);
        dfs(node->right, val, depth, current + 1);
    }
};
