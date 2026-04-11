// ============================================================
// Path Sum II — All Paths with Target Sum
// ============================================================
#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
    void dfs(TreeNode* node, int remain, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;
        path.push_back(node->val);
        remain -= node->val;
        if (!node->left && !node->right && remain == 0)
            result.push_back(path); // Copy path
        dfs(node->left, remain, path, result);
        dfs(node->right, remain, path, result);
        path.pop_back(); // Backtrack
    }
};
