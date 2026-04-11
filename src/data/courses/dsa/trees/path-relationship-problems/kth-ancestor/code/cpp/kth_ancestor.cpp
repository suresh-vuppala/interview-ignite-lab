// ============================================================
// Kth Ancestor in Binary Tree
// ============================================================
#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int findKthAncestor(TreeNode* root, int target, int k) {
        vector<TreeNode*> path;
        findPath(root, target, path);
        int idx = path.size() - 1 - k;
        return idx >= 0 ? path[idx]->val : -1; // -1 if no Kth ancestor
    }
    bool findPath(TreeNode* node, int target, vector<TreeNode*>& path) {
        if (!node) return false;
        path.push_back(node);
        if (node->val == target) return true;
        if (findPath(node->left, target, path) || findPath(node->right, target, path))
            return true;
        path.pop_back(); // Backtrack
        return false;
    }
};
