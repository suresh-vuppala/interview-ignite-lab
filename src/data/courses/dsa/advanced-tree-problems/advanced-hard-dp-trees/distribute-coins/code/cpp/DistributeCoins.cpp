struct TreeNode { int val; TreeNode *left, *right; TreeNode(int v):val(v),left(nullptr),right(nullptr){} };
#include <cmath>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: BFS simulation — move coins one step at a time — O(N * totalCoins)
// ============================================================
class Solution1 {
public:
    // Simulation is impractical — postorder DFS is standard
    // See Solution 2
    int distributeCoins(TreeNode* root) { int moves = 0; dfs(root, moves); return moves; }
    int dfs(TreeNode* n, int& moves) {
        if (!n) return 0;
        int l = dfs(n->left, moves), r = dfs(n->right, moves);
        moves += abs(l) + abs(r); // Each excess/deficit coin must pass through this node
        return n->val - 1 + l + r; // Excess coins at this subtree
    }
};

// ============================================================
// Solution 2: Postorder — count excess/deficit flow — O(N)
// ============================================================
class Solution2 {
    int totalMoves = 0;
    int dfs(TreeNode* n) {
        if (!n) return 0;
        int left = dfs(n->left), right = dfs(n->right);
        totalMoves += abs(left) + abs(right);
        return n->val - 1 + left + right; // +ve = excess, -ve = needs coins
    }
public:
    int distributeCoins(TreeNode* root) { totalMoves = 0; dfs(root); return totalMoves; }
};
