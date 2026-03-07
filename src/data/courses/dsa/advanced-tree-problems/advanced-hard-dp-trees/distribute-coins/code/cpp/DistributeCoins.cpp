// Time: O(N) | Space: O(H)

#include <cstdlib>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int moves = 0;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        moves += abs(left) + abs(right);
        return node->val + left + right - 1;
    }
    
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};
