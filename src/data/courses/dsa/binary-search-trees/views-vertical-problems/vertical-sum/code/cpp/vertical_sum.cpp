#include <map>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
class Solution {
public:
    vector<int> verticalSum(TreeNode* root) {
        if (!root) return {};
        map<int, int> sums;
        queue<pair<TreeNode*, int>> q; q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front(); q.pop();
            sums[hd] += node->val;
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<int> result;
        for (auto& [hd, s] : sums) result.push_back(s);
        return result;
    }
};
