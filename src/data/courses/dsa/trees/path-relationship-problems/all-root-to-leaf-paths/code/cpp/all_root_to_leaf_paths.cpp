// ============================================================
// All Root-to-Leaf Paths
// ============================================================
#include <vector>
#include <string>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) dfs(root, "", result);
        return result;
    }
    void dfs(TreeNode* node, string path, vector<string>& result) {
        path += to_string(node->val);
        if (!node->left && !node->right) { result.push_back(path); return; }
        if (node->left) dfs(node->left, path + "->", result);
        if (node->right) dfs(node->right, path + "->", result);
    }
};
