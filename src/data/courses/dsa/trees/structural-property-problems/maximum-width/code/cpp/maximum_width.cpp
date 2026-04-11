// ============================================================
// Maximum Width of Binary Tree
// ============================================================
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long minPos = q.front().second; // Normalize
            unsigned long long first, last;
            for (int i = 0; i < size; i++) {
                auto [node, pos] = q.front(); q.pop();
                pos -= minPos; // Prevent overflow
                if (i == 0) first = pos;
                if (i == size-1) last = pos;
                if (node->left) q.push({node->left, 2*pos});
                if (node->right) q.push({node->right, 2*pos+1});
            }
            maxWidth = max(maxWidth, (int)(last - first + 1));
        }
        return maxWidth;
    }
};
