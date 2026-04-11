// ============================================================
// Maximum Depth (Height) of Binary Tree
// ============================================================

#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// ============================================================
// Solution 1: Recursive DFS
// Time: O(N) | Space: O(H)
// ============================================================
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; // Base case: null → height 0
        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        return 1 + max(leftH, rightH); // 1 (current) + taller subtree
    }
};

// ============================================================
// Solution 2: Iterative BFS — Count Levels
// Time: O(N) | Space: O(W)
// ============================================================
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++; // One level processed
        }
        return depth;
    }
};
