#include <vector>
#include <queue>
#include <map>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int, vector<int>> cols;
        queue<pair<TreeNode*, int>> q; q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();
            cols[hd].push_back(node->val);
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<vector<int>> result;
        for (auto& [hd, col] : cols) result.push_back(col);
        return result;
    }
};
