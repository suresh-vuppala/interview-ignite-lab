struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Check each subtree, sum if BST — O(N²)
// ============================================================
class Solution1 {
    bool isBST(TreeNode* n, long mn, long mx) {
        if (!n) return true;
        if (n->val <= mn || n->val >= mx) return false;
        return isBST(n->left, mn, n->val) && isBST(n->right, n->val, mx);
    }
    int sum(TreeNode* n) { return n ? n->val + sum(n->left) + sum(n->right) : 0; }
public:
    int maxSumBST(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        if (isBST(root, LONG_MIN, LONG_MAX)) res = max(res, sum(root));
        res = max({res, maxSumBST(root->left), maxSumBST(root->right)});
        return res;
    }
};

// ============================================================
// Solution 2: Postorder — return (isBST, sum, min, max) — O(N)
// ============================================================
class Solution2 {
    struct Info { bool isBST; int sum; long mn, mx; };
    int maxSum = 0;
    Info dfs(TreeNode* n) {
        if (!n) return {true, 0, LONG_MAX, LONG_MIN};
        auto l = dfs(n->left), r = dfs(n->right);
        if (l.isBST && r.isBST && n->val > l.mx && n->val < r.mn) {
            int s = l.sum + r.sum + n->val;
            maxSum = max(maxSum, s);
            return {true, s, min((long)n->val, l.mn), max((long)n->val, r.mx)};
        }
        return {false, 0, 0, 0};
    }
public:
    int maxSumBST(TreeNode* root) { maxSum = 0; dfs(root); return maxSum; }
};
