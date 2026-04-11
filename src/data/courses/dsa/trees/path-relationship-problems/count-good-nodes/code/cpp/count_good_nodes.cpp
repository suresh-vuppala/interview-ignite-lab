class Solution {
public:
    // O(n) time — DFS tracking max value from root to current node
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        int count = (node->val >= maxSoFar) ? 1 : 0; // Good if >= max on path
        int newMax = max(maxSoFar, node->val);
        return count + dfs(node->left, newMax) + dfs(node->right, newMax);
    }
};