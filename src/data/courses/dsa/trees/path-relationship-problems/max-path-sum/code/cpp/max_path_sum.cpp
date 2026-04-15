struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Check all paths between all pairs — O(N²)
// ============================================================
class Solution1 {
    int maxGain(TreeNode* n, int& maxSum) {
        if(!n) return 0;
        int l=max(0,maxGain(n->left,maxSum)), r=max(0,maxGain(n->right,maxSum));
        maxSum=max(maxSum, n->val+l+r); // path through this node
        return n->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) { int res=INT_MIN; maxGain(root,res); return res; }
};

// ============================================================
// Solution 2: Single DFS postorder — O(N) Time, O(H) Space
// ============================================================
class Solution2 {
    int res = INT_MIN;
    int dfs(TreeNode* n) {
        if(!n) return 0;
        int l = max(0, dfs(n->left)), r = max(0, dfs(n->right));
        res = max(res, l + r + n->val); // Update global max
        return n->val + max(l, r);       // Return max one-side path
    }
public:
    int maxPathSum(TreeNode* root) { res=INT_MIN; dfs(root); return res; }
};
