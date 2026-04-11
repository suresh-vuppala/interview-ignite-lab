// ============================================================
// Max and Min Value in Binary Tree
// ============================================================

#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// ============================================================
// Solution 1: DFS — General Binary Tree
// Time: O(N) | Space: O(H)
// ============================================================
class Solution1 {
public:
    int findMax(TreeNode* root) {
        if (!root) return INT_MIN;
        return max({root->val, findMax(root->left), findMax(root->right)});
    }

    int findMin(TreeNode* root) {
        if (!root) return INT_MAX;
        return min({root->val, findMin(root->left), findMin(root->right)});
    }
};

// ============================================================
// Solution 2: BST Optimization — Follow Edges
// Time: O(H) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int findBSTMin(TreeNode* root) {
        while (root->left) root = root->left; // Leftmost = min in BST
        return root->val;
    }

    int findBSTMax(TreeNode* root) {
        while (root->right) root = root->right; // Rightmost = max in BST
        return root->val;
    }
};
