// ============================================================
// Count Good Nodes in Binary Tree
// ============================================================
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        int count = 0;
        if (node->val >= maxSoFar) count = 1; // Good node!
        maxSoFar = max(maxSoFar, node->val);   // Update max for children
        count += dfs(node->left, maxSoFar);
        count += dfs(node->right, maxSoFar);
        return count;
    }
};
