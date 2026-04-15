struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: For each node, check if BST + count size — O(N²)
// ============================================================
class Solution1 {
    bool isBST(TreeNode* n, long mn, long mx) {
        if (!n) return true;
        if (n->val <= mn || n->val >= mx) return false;
        return isBST(n->left, mn, n->val) && isBST(n->right, n->val, mx);
    }
    int size(TreeNode* n) { return n ? 1 + size(n->left) + size(n->right) : 0; }
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        if (isBST(root, LONG_MIN, LONG_MAX)) return size(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};

// ============================================================
// Solution 2: Postorder — return (isBST, size, min, max) — O(N)
// ============================================================
class Solution2 {
    struct Info { bool isBST; int size; long mn, mx; };
    int maxSize = 0;
    Info dfs(TreeNode* n) {
        if (!n) return {true, 0, LONG_MAX, LONG_MIN};
        auto l = dfs(n->left), r = dfs(n->right);
        if (l.isBST && r.isBST && n->val > l.mx && n->val < r.mn) {
            int sz = l.size + r.size + 1;
            maxSize = max(maxSize, sz);
            return {true, sz, min((long)n->val, l.mn), max((long)n->val, r.mx)};
        }
        return {false, 0, 0, 0};
    }
public:
    int largestBSTSubtree(TreeNode* root) { maxSize = 0; dfs(root); return maxSize; }
};
