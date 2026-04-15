struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Try all subsets of nodes for cameras — O(2^N)
// ============================================================
class Solution1 {
public:
    // Brute: check every subset — exponential
    // Greedy postorder is the standard approach — see Solution 2
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if (dfs(root, cameras) == 0) cameras++; // Root uncovered
        return cameras;
    }
    // Returns: 0=uncovered, 1=has camera, 2=covered
    int dfs(TreeNode* n, int& cam) {
        if (!n) return 2;
        int l = dfs(n->left, cam), r = dfs(n->right, cam);
        if (l == 0 || r == 0) { cam++; return 1; }
        if (l == 1 || r == 1) return 2;
        return 0;
    }
};

// ============================================================
// Solution 2: Greedy postorder — place cameras at parents of leaves — O(N)
// ============================================================
class Solution2 {
    int cameras = 0;
    // 0=needs coverage, 1=has camera, 2=already covered
    int dfs(TreeNode* n) {
        if (!n) return 2; // Null is "covered"
        int l = dfs(n->left), r = dfs(n->right);
        if (l == 0 || r == 0) { cameras++; return 1; } // Child needs coverage → place camera
        if (l == 1 || r == 1) return 2; // Child has camera → I'm covered
        return 0; // Both covered, I need coverage from parent
    }
public:
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};
