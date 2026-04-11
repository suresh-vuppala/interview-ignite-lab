// ============================================================
// Binary Tree Maximum Path Sum
// ============================================================
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

class Solution {
    int globalMax = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        globalMax = INT_MIN;
        maxGain(root);
        return globalMax;
    }
    // Returns max gain from this node going DOWN (single side)
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        // Max gain from left/right (ignore negatives with max(0,...))
        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));
        // Path THROUGH this node (uses both sides)
        int pathThrough = node->val + leftGain + rightGain;
        globalMax = max(globalMax, pathThrough);
        // Return to parent: can only extend ONE side
        return node->val + max(leftGain, rightGain);
    }
};
