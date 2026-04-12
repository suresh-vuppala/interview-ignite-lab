// ============================================================
// Two Sum in BST
// ============================================================
#include <unordered_set>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };

// Hash Set approach
class Solution {
    unordered_set<int> seen;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (seen.count(k - root->val)) return true;
        seen.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
