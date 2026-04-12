#include <vector>
#include <queue>
#include <map>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        if (!root) return {};
        map<int, int> hdMap;
        queue<pair<TreeNode*, int>> q; q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();
            hdMap[hd] = node->val; // Overwrite — last (deepest) wins
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<int> result;
        for (auto& [hd, val] : hdMap) result.push_back(val);
        return result;
    }
};
